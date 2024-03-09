//Kajetan Ozog
#ifndef BACA_ZAD_A_BITWISE_OPERATIONS_H
#define BACA_ZAD_A_BITWISE_OPERATIONS_H

void helper2(int* number, int n, int p, char* chain);
void helper(char* chain, int n, int* number);
int counter(int num);

void Emplace(char* chain, int* number);
void Insert(char* chain, int* number);
void Erase(char* chain, int* number);
void Print(int number, char* chain);
bool Emptiness(int number);
bool Nonempty(int number);
bool Member(char* chain, int number);
bool Disjoint(int num1, int num2);
bool Conjunctive(int num1, int num2);
bool Inclusion(int x, int y);
bool Equality(int x, int y);
void Union(int x, int y, int* z);
void Intersection(int x, int y, int* z);
void Symmetric(int x, int y, int* z);
void Difference(int x, int y, int* z);
void Complement(int x, int* z);
int Cardinality(int number);
bool LessThen(int x, int y);
bool LessEqual(int x, int y);
bool GreatEqual(int x, int y);
bool GreatThen(int x, int y);


#endif //BACA_ZAD_A_BITWISE_OPERATIONS_H
