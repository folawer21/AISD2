#ifndef VECTORTESTS_H
#define VECTORTESTS_H


#include <iostream>
#include "cassert"

void Vector_from_array_test();//проверка Создания вектора из массива
void Vector_from_vector_test();//проверка Создания вектора из другого вектора
void Append_test();//проверка Добавки элемента в вектора
void Sum_with_zero_test();//проверка сложения с нулевым вектором
void Sum_vectors_test();//проверка сложения с вектором
void Multiply_on_zero_test();//проверка умножения на нулевой скаляр
void Multiply_on_negative_test();//проверка умножения на отрицательный скаляр
void Multiply_on_positive_test();//проверка умножения на положительный скаляр
void Vector_Norm_test();//Проверка вычисления нормы вектора
void Dot_product_test();// Проверка вычисления скалярного произведения векторов
void Vector_tests();//Все тесты в месте для вызова
#endif //VECTORTESTS_H
