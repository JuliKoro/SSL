#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct A {
	int a;
	struct {
		int b;
		float c;
	};
	double d;
	struct X {
		char e;
	} x;
	long f;
};

int main(void)
{
	struct A a = {3};
	printf("Sizeof struct: %ld\n", sizeof(a));
	printf("a = %d\nb = %d\nc = %f\nd = %g\ne = %c\nf = %ld\n\n", a.a, a.b, a.c, a.d, a.x.e, a.f);
	//printf("a = %d\nb = %d\nc = %f\nd = %g\ne = %c\nf = %ld\n\n", a.a, a.b, a.c, a.d, a.e, a.f); //main5.c:23:92: error: ‘struct A’ has no member named ‘e’
	a.x.e = 'J';
	a.f = 555;
	printf("a = %d\nb = %d\nc = %f\nd = %g\ne = %c\nf = %ld\n\n", a.a, a.b, a.c, a.d, a.x.e, a.f);
	printf("Offset a = %ld\tSizeof a = %ld\n", offsetof(struct A, a), sizeof(a.a));
	printf("Offset b = %ld\tSizeof b = %ld\n", offsetof(struct A, b), sizeof(a.b));
	printf("Offset c = %ld\tSizeof c = %ld\n", offsetof(struct A, c), sizeof(a.c));
	printf("Offset d = %ld\tSizeof d = %ld\n", offsetof(struct A, d), sizeof(a.d));
	printf("Offset x.e = %ld\tSizeof x.e = %ld\n", offsetof(struct A, x.e), sizeof(a.x.e));
	printf("Offset x = %ld\tSizeof x = %ld\n", offsetof(struct A, x), sizeof(a.x));
	printf("Offset f = %ld\tSizeof f = %ld\n", offsetof(struct A, f), sizeof(a.f));
	return EXIT_SUCCESS;
}
