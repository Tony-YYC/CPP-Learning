# 对象和类

## 对象数组

创建对象数组

```c++
Stock mystuff[4]; // creates an array of 4 Stock objects
```

创建对象数组，且没有显式初始化时，将调用默认构造函数。
故这要求这个类是以下两种情况之一：
- 没有显式地定义任何构造函数（在这种情况下，将使用不执行任何操作的隐式默认构造函数）
- 定义了一个显式默认构造函数（根据这个默认构造函数操作）
否则将出错。

创建对象数组时可以进行显式初始化。可以通过如下的构造函数来初始化数组元素。

```c++
const int STKS = 4;
Stock stocks[STKS] = {
    Stock("NanoSmart", 12.5, 20),
    Stock("Boffo Objects", 200, 2.0),
    Stock("Monolithic Obelisks", 130, 3.25),
    Stock("Fleep Enterprises", 60, 6.5)
    };
```

注意：
- 如果类包含多个构造函数，则可以对不同的元素使用不同的构造函数。
- 如果声明的时候仅初始化数组的部分元素，其余元素将使用默认构造函数进行初始化。
看如下的例子

```c++
const int STKS = 10;
Stock stocks[STKS] = {
    Stock("NanoSmart", 12.5, 20),
    Stock(),
    Stock("Monolithic Obelisks", 130, 3.25),
    };
```

上述代码使用Stock(const string & co, long n, double pr)初始化stock[0]和stock[2]，使用构造函数Stock()初始化stock[1]。由于该声明只初始化了数组的部分元素，因此余下的7个元素将使用默认构造函数进行初始化。

注意初始化对象数组时，首先使用默认构造函数创建数组元素，然后花括号中的构造函数将创建临时对象，然后将临时对象的内容复制到相应的元素中。
这意味着**要创建类对象数组，则这个类必须有默认构造函数。**

## 类作用域

- 在类中定义的名称（如类数据成员名和类成员函数名）的作用域都为整个类
- 作用域为整个类的名称只在该类中是已知的，在类外是不可知的，因此不同类中使用相同的类成员名不会冲突。
- 类作用域意味着不能从外部直接访问类的成员。
  - 要调用公有成员函数，必须通过对象
  - 在定义成员函数时，必须使用作用域解析运算符

### 作用域为类的常量

先设想一个创建数组的场景，然后来看一种**完全错误**的做法：

```c++
class Bakery
{
private:
    const int Months = 12; // declare a constant? FAILS
    double costs[Months];
    ...
```

因为声明类只是描述了对象的形式，并没有创建对象。因此，在创建对象前，没有存储Months的位置，这会导让创建costs数组时出现问题。

这种情况下可以使用两种方法：
1. 在类中声明一个枚举来表示数组长度
  - 在类声明中声明的枚举的作用域为整个类，因此可以用枚举为整型常量提供作用域为整个类的符号名称。
  - 注意：用这种方式声明枚举并不会创建类数据成员。枚举并不是类的一个对象，它只是一个别名。可以将它理解为，在整个类的代码中，编译器会将Months替换为30。
  - 这里使用枚举只是为了创建符号常量，并不打算创建枚举类型的变量，因此不要提供枚举名。
2. 使用关键字static
  - 这将创建一个名为Months的常量，该常量将与其他静态变量存储在一起，而不是存储在对象中。

```c++
class Bakery
{
private:
    enum {Months = 12};
    double costs[Months];
    ...
```

```c++
class Bakery
{
private:
    static const int Months = 12;
    double costs[Months];
    ...
```

### 作用域为类的枚举

如果使用普通的枚举，下面这种情况将无法通过编译，因为egg Small和t_shirt Small位于相同的作用域内，这两个相同的名称将发生冲突。

```c++
enum egg {Small, Medium, Large, Jumbo};
enum t_shirt {Small, Medium, Large, Xlarge};
```

C++11提供了一种新枚举，其枚举量的作用域为类，可以解决这种问题。声明方式如下（可使用关键字struct代替class）：

```c++
enum class egg {Small, Medium, Large, Jumbo};
enum class t_shirt {Small, Medium, Large, Xlarge};
```

自然地，调用时要使用枚举名来限定枚举量

```c++
egg choice = egg::Large; // the Large enumerator of the egg enum
t_shirt Floyd = t_shirt::Large; // the Large enumerator of the t_shirt enum
```

C++11规定类作用域内的枚举不能隐式类型转换为整型。下面的代码展示两者的区别：

```c++
enum egg_old {Small, Medium, Large, Jumbo}; // unscoped
enum class t_shirt {Small, Medium, Large, Xlarge}; // scoped
egg_old one = Medium; // unscoped
t_shirt rolf = t_shirt::Large; // scoped
int king = one; // implicit type conversion for unscoped
int ring = rolf; // not allowed, no implicit type conversion
if (king < Jumbo) // allowed
    std::cout << "Jumbo converted to int before comparison.\n";
if (king < t_shirt::Medium) // not allowed
    std::cout << "Not allowed: < not defined for scoped enum.\n";
```

当然，你可以进行显式类型转换：

```c++
int Frodo = int(t_shirt::Small); // Frodo set to 0
```

底层类型：
- 对于作用域内枚举，C++11规定底层类型为int。当然，标准也允许手动指定底层类型。在下面这个类型中，:short将底层类型指定为short。
- 在C++11中，也可使用这种语法来指定常规枚举的底层类型，但如果没有指定，编译器选择的底层类型将随实现而异。

```c++
enum class : short pizza {Small, Medium, Large, XLarge};
```

## 总结

使用OOP方法解决编程问题：
1. 根据一个模块与程序之间的接口来描述数据，从而指定如何使用数据
2. 设计一个类来实现该接口
3. 使用私有数据成员存储信息，公有成员函数（又称为方法）提供访问数据的唯一途径
4. 类将数据和方法组合成一个单元，其私有性实现数据隐藏

将类声明分成两部分存储：
1. 类声明（包括由函数原型表示的方法）应放到头文件中。
2. 定义成员函数的源代码放在方法文件中。

这样从理论上说，只需知道公有接口就可以使用类。
- 这也是当你在项目中使用非header-only的库时，通常会有一个指定了库中各种函数原型的header以及一个编译好的lib/dll/so文件的原因。库的实现已经被编译好了，你是看不到其中各个函数的具体定义的，但是你有记录了库中函数原型的header，你就可以在自己的项目中使用它了。（当然链接的时候要指定链接器在相应的lib文件中搜索编译好的函数）
- 程序不应依赖于类的实现细节--解耦
- 只要程序和类只通过定义接口的方法进行通信，程序员就可以随意地对任何部分做独立的改进，而不必担心这样做会导致意外的不良影响。

类是用户定义的类型，对象是类的实例。
- 这样一来，可以将对象理解为其类的那种类型的变量
  - C++试图让用户定义的类型尽可能与标准类型类似
  - 可以声明对象、指向对象的指针和对象数组
  - 可以按值传递对象、将对象作为函数返回值、将一个对象赋给同类型的另一个对象。
  - 如果提供了构造函数，则在创建对象时，可以初始化对象。（注意默认构造函数的特性和相关使用方法）
  - 如果提供了析构函数方法，则在对象消亡后，程序将执行该函数。
- 每个对象都存储自己的数据，而共享类方法。

this指针
- 如果希望成员函数对多个对象进行操作，可以将额外的对象作为参数传递给它。
- 如果方法需要显式地引用调用它的对象，可以使用this指针。
  - 由于this指针被设置为调用对象的地址，因此*this是该对象的别名。

类很适合用于描述抽象数据类型（ADT）。公有成员函数接口提供了ADT描述的服务，类的私有部分和类方法的代码
提供了实现，这些实现对类的客户隐藏。
