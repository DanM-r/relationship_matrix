# Relationship Matrix

It's a matrix in which one element relates in a certain integer value to each different element. The matrix must follow the next characteristics:
1. **Squared**: The size grows in an uniform way. The amount of rows is the same as the amount of columns.
2. **Dynamic**: Can grow and decrease in size during execution. It can be done with a linked list in which each element is a linked list.
3. **Relationship Data Type**: Integer in a range from 0 to infinity. 0 means no relationship, whereas !0 means the depth of the relationship.
4. **Not Commutable**: It can allow commutability, but it isn't by default.

The matrix may allow to *add elements, remove elements, modify relationship between 2 elements, show the relationship between 2 elements*. There must be three operator overloadings: `( + and += )`: adding, `( -- )`: removing, `( << )`: printing _cout_.

## Implementation

A template class of a linked list of linked lists of integers.

## Questions
- ¿Podria por medio de sobrecarga de operadores hacer algo asi? `matrix[ 0 ][ 0 ] = 0`?
    > Si se puede, con la sobrecarga de los brackets
- ¿Establecer, Modificar relaciones?
    > Al final siempre es modificar la relacion.
- ¿Se podria usar `std::list`?
    > No
- ¿Como debe ser la estructura cuando se ejecuta todo el programa?
    > Hacer un menu que le pida al usuario que programa quiere correr. Al salirse de uno, vuelve al menu.
- ¿?
    >

## Dating Social Media

RM made of Users in which the relationships change by giving likes.

## Metro Tickets

RM made of Cities in which the relationships change by the cost of each ticket from city to city.

## Company Coworkers

RM made of Employees in which the relationships change when they work together. **Note**: It's commutable.


Quiz plantillas de hoy en 8
