# Рассмотрим следующее объявление классов

class A:
    pass

class B(A):
    pass

class C:
    pass

class D(C):
    pass

class E(B, C, D):
    pass


# Какие последовательности могут являться корректным порядком разрешения методов для класса E?