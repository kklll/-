# <center>Java学习笔记</center>

# javastudy
## &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Java学习笔记

#### 注意
>【1】使用时应该注意文件名要与class名一样。（当类被public修饰时）  
>【2】main方法只能用public和static来修饰.  
>【3】面向对象的三个特征：继承、多态、封装。  
>【4】数据类型：基本类型和引用类型 基本类型：布尔类型、数值类型。引用类型：类、接口、数组。
对象：实例和数组  
>【5】\b退格符，\r回车符  
>【6】byte：1字节（内存八位），short：2，int：4，long：8，char：2，float：4，double：8  
#### 面向对象：  




>[1]static修饰的类方法属于类，不属于实例。  
>[2]方法可以作为返回值（this的使用）  
>[3]可变参数定义的方法：  
>``public static void main（int a，String[] ... books``)  
>或者：  
>``public static void main(int a, String[] books)``  
>下面这种方法在调用时为:  
>``main(5,new String []{"疯狂java讲义","小王子","谁的青春不迷茫"})``  
><font color=#ff0000 >推荐使用第一种。 </font>   
>类变量在建立类的
>
>
>
>
>
>
>
>
>时候就会初始化，与实例变量不同，实例变量实在创建实例的时候才分配内存，且实例变量随新建变量会在堆区储存，而类变量不会随对象的新建而变化。
>- 创建处于其包下的实例，在调用构造器的时候要指定包名，或者直接使用import语句  
 


## import
### java常用包:
* java.lang:Java的核心库文件String，Math，System，Thread。无需导入
* java.util：Java工具和接口框架等，Arrays，List，Set等。
* java.net：java网络编程的类和接口。
* java.io：输入输出。
* java.text：java格式化的类
* java.sql:包含了java进行JBDC编程的类
* java.awt：抽象窗口工具集（GUI）
* java.swing：swing图形用户界面编程的相关类。  
  
## extends  
### 继承
* 关键字：extends（扩展)
* java的子类不能得到父类的构造器
* super父类    


### 转型
* 父类变量可以引用任何一个子类对象,而子类变量不能引用父类对象 
* 向上转型可能会丢失子类中多余的方法，特征（向上转型为子类对象赋值给父类引用变量）
* 向下转型（将父类实例转换为子类类型），那么这个对象的实际类型必须是子类类型。  


### instanceof运算符  

* 前面的类与后面的类相同或者有继承关系  
* Object类是所有类的父类。
---
### 类的复用
1. 可以使用类的继承，子类继承父类的特性形成复用。
2. 将原来的父类组合到原来的子类，作为子类的一个组成部分  
```java    
public class test1 {
    static class Animal {
        private void beat() {
            System.out.println("心脏在跳动");
        }

        public void breath() {
            beat();
            System.out.println("正在呼吸");
        }
    }

    class Bird {
        private Animal a;

        public Bird(Animal a) {
            this.a = a;
        }

        public void breath() {
            a.breath();
        }

        public void fly() {
            System.out.println("我在天空飞!");
        }
    }

    public static void main(String[] args) {
        Animal a1=new Animal();
        a1.breath();
    }
}
```

### 包装类
----
-  功能：  

    	将基本变量类型转换为对象类型（装箱）
		将对象类型转换为基本变量类型（拆箱） 

- 进行两个封装类的实例比较比较复杂，因为类实例实际是引用类型，两个包装类指向同一个对象才会TRUE。
- int类型中系统向-128——127的数字计入缓存，不会出现上述现象。
- compare方法（所有包装类都具有的类），参数为两个比较值。以此来比较基本数据类型是否相同

### ==和equal方法


-  ==如果为基本类型变量则比较数值，引用类型的话比较地址
-  equal判断两个引用变量的值是否相等（所有引用变量都可以调用）。

- <font color=#8470FF >推荐使用第一种。 </font>

### final修饰符
-  final修饰符修饰的成员变量必须显式的初始值，初始化后其值不能改变。
-  java不允许直接访问final访问的成员变量，需要使用方法来访问。

### 抽象类
- 抽象类和抽象方法的不同点
   - 抽象类和方法用abstract修饰，抽象类不能被实例化，只能通过被其他子类继承来定义方法。
   - private和abstract不能同时使用。

## 接口
- 接口的定义使用关键字interface 接口名 extends 父接口1，父接口2···
- 接口内不能含有构造器和初始化定义模块。（允许抽象方法，类方法和默认方法，私有方法。）
* 接口描述类具有什么功能,而不给出每个功能的具体实现.
* 一个类可以实现多个接口
- 接口中定义默认方法需要用default来修饰
- 接口的功能可以用来定义常量，被其它类实现。
- 接口的实现使用implement关键字，格式为
   ```java
    [修饰符] class 类名 extends 父类 implement 接口1，2···
    {

    }
    ```
```JAVA
package dataandvar.test;
   public interface output{
       int max=50;
       void out();
       void getdata();
       default void print(String []msgs)
       {
           for (String msg:msgs) {
               System.out.println(msg);
           }
       }
       default void test(){
           System.out.println("默认的test方法");
       }
       static String staticTest(){
           return ("接口类的test方法");
       }
   }
```
```JAVA
package dataandvar;

import dataandvar.test.output;

public class DataType {
    public static void main(String[] args) {
        System.out.println(output.max);
        System.out.println(output.staticTest());
    }
}
```







### 接口与内部类
## 接口

* 接口描述类具有什么功能,而不给出每个功能的具体实现.
* 一个类可以实现多个接口

#### Comparable接口的实例

我们希望对Employee数组进行排序,调用`Arrays.sort()`方法

如果没有实现`Comparable`接口的话,sort会抛出一个异常:

```java
Employee employee = new Employee("Rick", 1, 7000);
Employee employee2 = new Employee("Rick", 1, 8000);
Employee[] employeeList = {employee2, employee};
Arrays.sort(employeeList);
System.out.println(Arrays.toString(employeeList));
```

```java
//异常信息:
Exception in thread "main" java.lang.ClassCastException: week01.extend.Employee cannot be cast to java.lang.Comparable
	at java.util.ComparableTimSort.countRunAndMakeAscending(ComparableTimSort.java:320)
	at java.util.ComparableTimSort.sort(ComparableTimSort.java:188)
	at java.util.Arrays.sort(Arrays.java:1246)
	at Main.main(Main.java:14)
```

所以我们需要实现`Comparable`接口,才能使用`sort`方法对数组排序.Comparable接口可以添加一个泛型参数

```java

public class Employee extends Person implements Comparable<Employee>{
    private int salary;

    public Employee() {
    }

    public Employee(String name, int sex, int salary) {
        super(name, sex);
        this.salary = salary;
    }

    @Override
    public String getDescription() {
        return super.getName() + " " + super.getSex() + " " + getSalary();
    }

    public int getSalary() {
        return salary;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "name='" + super.getName() + '\'' +
                ", sex=" + super.getSex() +
                ", salary=" + salary +
                '}' + '\n';
    }



    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true; //如果引用相同
        if (obj == null) return false; //如果比较的对象为null,一定不相等
        if (getClass()  != obj.getClass()) return false; //getClass获取对象的类.如果两个对象类都不相同,那么这两个对象肯定不相同
        //排除了前面的条件后,就可以开始判断这两个类的信息是否相同
        Employee other = (Employee) obj;
        return this.getName() == other.getName()
                && this.getSalary() == other.getSalary()
                && this.getSex() == other.getSex();
    }


    @Override
    public int compareTo(Employee o) {
        return Integer.compare(getSalary(), o.getSalary());
    }
}

```

Employee作为父类实现了Comparable接口之后,Manager作为子类,就可以重写父类的`compareTo()`方法,编写针对Manager的比较方式

#### 接口的特性

* 接口不是类,不能创建一个接口的**实例** ,比如 不允许`new Comparable<>();`
* 接口中的所有方法默认`public`
* 可以声明一个接口的 **变量**,这个变量必须 **引用实现了接口的类对象**.这是一种向上转型.
  * 比如`Comparable comparable = new Employee();`
* 接口也可以被扩展.一个接口可以继承另一个接口
* 接口中 **不能包含实例域或静态方法**,但是接口可以包含**常量** 
* 一个类只能拥有一个父类,但是可以实现多个接口

### 接口与内部类实战

我们首先创建一个`JDBCObject`类,这个类用于和数据库进行交互,实现`save` `update` `delete` `query`等方法

继承了`JDBCObject`的类,都可以调用save等方法和数据库交互,在数据库中存储信息.

```java

public class JDBCObject {
    public void save() {
        //假设save方法是异步进行网络请求
        Response response = JDBCHelper.getInstance().save(this); //保存对象,获取Response响应
        //响应不为空 并且响应码为201 (201在HTTP协议中表示请求成功并且服务器创建了新的资源)
        if (null != response && response.code() == 201) {
            if (response.code() == 201) {
                try {
                    //获取服务器的响应的内容(json是一种数据对象的字符串映射)
                    String json = response.body().string(); 
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }

        } else {
            //save方法请求失败
        }
    }
}
```

```java
//Person继承JDBCObject
public abstract class Person extends JDBCObject{
    ...
}
```

我们希望在存储成功时获取服务器的响应信息,而在存储失败时获取异常信息,这时候就需要**利用接口实现回调**

#### 回调

例子:    你到一个商店买东西，刚好你要的东西没有货，于是你在店员那里留下了你的电话,我们继续去做自己的事情.过了几天店里有货了，店员就打了你的电话，然后你接到电话后就知道店里有了货.

在我们这里就是: 我们希望在服务器的数据库中存储一个对象, 在服务器的数据库中存储需要网络通信,会有一定的延迟,所以我们留下一个SaveListener接口(在子线程中执行存储过程). 当与服务器交互存储完毕后,子线程会通知主线程:我已经得到了服务器响应信息,你现在可以对这些信息进行处理了.

#### 创建接口

```java
public class JDBCDao {
    public interface SaveListener{
        void onSucceed(String response);

        void onFail(Exception e);
    }
}
```

#### 利用接口通知save方法调用成功或失败信息

* 添加接口参数
* 利用接口通知信息

```java
public class JDBCObject {
    public void save(JDBCDao.SaveListener listener) {
        Response response = JDBCHelper.getInstance().save(this); //获取Response响应
        //响应不为空 并且响应码为201 (201在HTTP协议中表示请求成功并且服务器创建了新的资源)
        if (null != response && response.code() == 201) {
            if (response.code() == 201) {
                try {
                    String json = response.body().string(); //数据对象的字符串映射
                    listener.onSucceed(json);
                } catch (IOException e) {
                    e.printStackTrace();
                    listener.onFail(e);
                }
            }
        } else {
            //save方法请求失败
            Exception e = new Exception("save failed!");
            listener.onFail(e);
        }
    }
}
```

#### 调用save方法

* 现在我们可以看到,save方法要求传入一个实现了`SaveListener`的类对象.我们有许多种方法可以实现

##### 方法1: 每次调用save,创建一个类实现SaveListener方法,对响应信息进行处理.

* 特别麻烦

##### 方法2: 内部类(定义在一个类中的类)

我们可以在Main中定义一个静态的`ResponseHandler`,实现SaveListener接口.

```java
public class Main {
    //内部类,声明为静态是因为在
    static class ResponseHandler implements JDBCDao.SaveListener {
        @Override
        public void onSucceed(String response) {
            System.out.println(response);
            System.out.println(response.toUpperCase());
        }

        @Override
        public void onFail(Exception e) {

        }
    }

    public static void main(String[] args) {
        Employee employee2 = new Employee("Rick2", 1, 8000);
        Manager manager = new Manager("SuperRick", 1, 7000, 5000);
        ResponseHandler responseHandler = new ResponseHandler();
        manager.save(responseHandler);

    }
}
```

内部类存在的问题:

* 创建的内部类只使用了很少次,用处不大

* 如果我们想在每次调用save方法对response做不同的处理的话,要在Main类中创建许多个不同的内部类

##### 这时可以使用方法内部类 (定义在方法中的类)

```java
public static void main(String[] args) {
        class ResponseHandler implements JDBCDao.SaveListener {
            @Override
            public void onSucceed(String response) {
                System.out.println(response);
                System.out.println(response.toUpperCase());
            }

            @Override
            public void onFail(Exception e) {

            }
        }

        Employee employee2 = new Employee("Rick2", 1, 8000);
        Manager manager = new Manager("SuperRick", 1, 7000, 5000);
        ResponseHandler responseHandler = new ResponseHandler();
        manager.save(responseHandler);
}
```

* 目前仍然存在的问题是,这个类的作用仅仅是用于实现SaveListener接口,它的作用仅仅用于在save方法中传递信息

  因此完全可以使用匿名内部类: **在创建对象的同时,定义类**

  * 匿名内部类没有类名,只有类的信息

```java
public static void main(String[] args) {
        Employee employee2 = new Employee("Rick2", 1, 8000);
        Manager manager = new Manager("SuperRick", 1, 7000, 5000);

        JDBCDao.SaveListener listener = new JDBCDao.SaveListener() {
            //private int x = 0; //也可以在匿名内部类中定义成员变量

            @Override
            public void onSucceed(String response) {
                System.out.println(response);
            }

            @Override
            public void onFail(Exception e) {

            }
        };

        manager.save(listener);
    }
```

##### 最简洁的方式:  用匿名内部类对象作为参数

```java
public static void main(String[] args) {
        Employee employee2 = new Employee("Rick2", 1, 8000);
        Manager manager = new Manager("SuperRick", 1, 7000, 5000);
        manager.save(new JDBCDao.SaveListener() {
            @Override
            public void onSucceed(String response) {
                System.out.println(response);
            }

            @Override
            public void onFail(Exception e) {

            }
        });
    }
```
