# Object Oriented Programming with C

Example of tiny and clean object oriented C style.

Web is full of similar ideas and implementations.
Here trying to have as clean as possible,
but still supporting most of the features of OOP in reusable ways.


## Building

Get [meson](http://mesonbuild.com) and [ninja](https://ninja-build.org).

After that build it:

    mkdir build
    cd build
    meson ..
    ninja


## Object

Object is the base class for all other objects.
Class itself is separated in two parts: data and methods.
Data contains pointer to methods structure and other class data values.

Object itself has only two methods: `type` and `dtor`.
When creating object, special method called `object_new` is called,
so constructor is not part of the object method vtable.

Methods are defined later on, and mapped to object in `object_init` method.

For reference, please see [object.h](inc/object.h)

## Inheritance

Upon inheritance a new class is created, and `Object` item is defined on it's data structure.
This way we embed the parent class data to new class data.

Similar way new class has operations defined separately in a structure.
One could do dynamic method finder and mapping to parent class methods,
but design rule was to have as direct method calls as possible.
This means that operations structure entries needs to be copied (multiplied) from parent.
It breaks [DRY](https://en.wikipedia.org/wiki/Don%27t_repeat_yourself) rule to promote performance.

Mapping methods from object to inherited class operations structure is encouraged.
It needs from caller side to cast object properly before calling to prevent compilation warnings.

For reference, please see [str.h](inc/str.h) and [str.c](src/str.c)

## Destructor

Deleting object is manual job, and upon that a destructor must be called.
It frees the memory used by object, and object parents.

It must be noted that `free` needs to be called only once.
On this case Object has the call on it's `object_del` method.
Because passed object points to the original object, whole object is freed at that point.

One idea could be implementing, or including, a garbage collector to free objects automatically.
Second, and probably better, idea is to introduce reference counting.
