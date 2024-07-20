# LinkList 
this class write by c++(*static language*)
this linklist has one sided, it mean's you can just go a head , you can't return
we have a table method's hear :
| name | Description |
| :----------- | :----------- |
| **linkList** (constructor) | to create an object from class , this method have one arg to set first value (head of node) *you can use without arg to* |
| **push** | to insert value at the end of current list |
| **pop** | to delete last node value from list |
| **insert** | to insert value in target index of list |
| **contain** | to check list has target value |
| **swap** | to swap two node |
| **print** | to print all node with value like array |
| **size** | return size of list |
| **reverse** | return revese of list |

## let's see method's with example
# 1. Constructor
as you khow we can create object from class with constructor
```cpp
linkList<int> list(3);
```
or with out first value
```cpp
linkList<int> list;
```
# 2. push
in this method if we have first node , this value added in back of list
else if we dont have first node , this value added in first node
```cpp
list.push(3);
```
# 3. pop
this method return none , it means creat for just delete last value
```cpp
list.pop();
```
# 4. insert
```cpp
linkList<int> list(3);
list.insert(0,1);
list.print();
```
as you know the output is => `1 3`
# 5.swap
```cpp
list.swap(1,3);
```
*note : this method has 2 args as you should use value , not index*
# 6.reverse
```cpp
linkList<int> rev = list.reverse();
```

### the class have an small bugs as i try to fixed it soon =)
