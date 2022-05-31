#ifndef VECTORLISTTESTS_H
#define VECTORLISTTESTS_H
#include <iostream>
#include "cassert"

void VectorList_from_array_test();//проверка Создания вектора из массива
void VectorList_from_Vector_test();//проверка Создания вектора из другого вектора
void List_Append_test();//проверка Добавки элемента в вектора
void List_Sum_with_zero_test();//проверка сложения с нулевым вектором
void List_Sum_VectorLists_test();//проверка сложения с вектором
void List_Multiply_on_zero_test();//проверка умножения на нулевой скаляр
void List_Multiply_on_negative_test();//проверка умножения на отрицательный скаляр
void List_Multiply_on_positive_test();//проверка умножения на положительный скаляр
void VectorList_Norm_test();//Проверка вычисления нормы вектора
void List_Dot_product_test();// Проверка вычисления скалярного произведения векторов
void List_VectorList_tests();//Все тесты в месте для вызова

#endif //VECTORLISTTESTS_H
