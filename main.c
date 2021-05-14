#include <stdio.h>
#include <stdarg.h>
#include "libftprintf.h"

int main() {
	//char str[100] = "%0000007.24d HelloWorld %";

	//char *s = "HappyNewYear";
	int num = -1534;
	//long lnum = -21415790876;
	unsigned int unum = 4294967290;
	//int *p = &num;

	/*int		a = -4;
	int		b = 0;*/
	char	c = 'a';
	/*int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";*/
	char	*p = "-12";
	/*char	*q = "0";
	char	*r = "%%";*/
	char	*s = "-2147483648";
	//char	*t = "0x12345678";
	//char	*u = "-0";*/
	char *pc = s;
	char **ps = &s;
	//char *ptr;

	/*printf("\n-------------------------TEST OUTPUT----------------------\n");
	char *str21 = "HelloWorld0%%%%00%-10.100ddddd%d\n";
	char *tail_str = ft_strdup(str21);

	printf("\ntail_str = %s\n", tail_str);
	printForCheck(tail_str, prf);

	printf("\n-------------------------TEST PARSING----------------------\n");
	char *str1 = "%0.*d\n";
	char *copy_str = ft_strdup(str1);
	char str2[100] = "%-*s\n";
	char str3[100] = "%--------*.c\n";
	char str4[100] = "%d\n";
	char str5[100] = "%0*d\n";
	char str6[100] = "%000000*.*d\n";
	char str7[100] = "%0.15d\n";
	char str8[100] = "%0--*.15v\n";
	char str9[100] = "%----0-3.*3d\n";
	char str10[100] = "%0.15.X\n";
	char str11[100] = "%----*99.-15\n";
	char str12[100] = "%----*99.15d\n";
	char str13[100] = "%%%%%% %----*99.15i\n";*/


	printf("\n----------------------TEST OUTPUT CHAR--------------------\n");
	printf("printf    --- test1 = %---*c\n", 8, c);
	ft_printf("ft_printf --- test1 = %---*c\n", 8, c);
	printf("printf    --- test2 = %10c\n", c);
	ft_printf("ft_printf --- test2 = %10c\n", c);
	printf("printf    --- test3 = %c\n", c);
	ft_printf("ft_printf --- test3 = %c\n", c);
	printf("printf    --- test4 = %--c\n", c);
	ft_printf("ft_printf --- test4 = %--c\n", c);
	printf("printf    --- test5 =%--c param1\n", c);
	ft_printf("ft_printf --- test5 =%--c param1\n", c);
	printf("printf    --- test6 = %---*c\n", 8, c);
	ft_printf("ft_printf --- test6 = %---*c\n", 8, c);
	printf("printf    --- test7 =%10c\n", c);
	ft_printf("ft_printf --- test7 =%10c\n", c);


	printf("\n----------------------TEST OUTPUT STR--------------------\n\n");
	printf("printf    --- test1 =%*s\n", 15, "HelloWord");
	ft_printf("ft_printf --- test1 =%*s\n", 15, "HelloWord");
	printf("printf    --- test2 =%*.s\n", 4, "HelloWord");
	ft_printf("ft_printf --- test2 =%*.s\n", 4, "HelloWord");
	printf("printf    --- test3 =%-*.5s\n", 6, "HelloWord");
	ft_printf("ft_printf --- test3 =%-*.5s\n", 6, "HelloWord");
	printf("printf    --- test4 =%5.*s\n", 8, "HelloWord");
	ft_printf("ft_printf --- test4 =%5.*s\n", 8, "HelloWord");
	printf("printf    --- test5 =%5.*s\n", 9, "HelloWord");
	ft_printf("ft_printf --- test5 =%5.*s\n", 9, "HelloWord");
	printf("printf    --- test6 =%15.*s\n", -4, "HelloWord");
	ft_printf("ft_printf --- test6 =%15.*s\n", -4, "HelloWord");
	printf("printf    --- test7 =%-15.*s\n", 4, "HelloWord");
	ft_printf("ft_printf --- test7 =%-15.*s\n", 4, "HelloWord");
	printf("printf    --- test8 =%*.*s\n", 15, 4, "HelloWord");
	ft_printf("ft_printf --- test8 =%*.*s\n",15, 4, "HelloWord");
	printf("printf    --- test9 %%%%%% =%---*s text\n", 15, "HelloWord");
	ft_printf("ft_printf --- test9 %%%%%% =%---*s text\n", 15, "HelloWord");
	printf("printf    --- test10 %%%%%% =%---*s text\n", 15, NULL);
	ft_printf("ft_printf --- test10 %%%%%% =%---*s text\n", 15, NULL);
	printf("printf    --- test10 %%%%%% =%.*s text\n", 4, NULL);
	ft_printf("ft_printf --- test10 %%%%%% =%.*s text\n", 4, NULL);


	printf("\n----------------------TEST OUTPUT INT--------------------\n\n");
	printf("printf    --- test1 =%0d\n", num);
	ft_printf("ft_printf --- test1 =%0d\n", num);
	printf("printf    --- test2 =%*.d\n", 4, num);
	ft_printf("ft_printf --- test2 =%*.d\n", 4, num);
	printf("printf    --- test3 =%-*.5d\n", 6, num);
	ft_printf("ft_printf --- test3 =%-*.5d\n", 6, num);
	printf("printf    --- test4 =%15.*d\n", 8, num);
	ft_printf("ft_printf --- test4 =%15.*d\n", 8, num);
	printf("printf    --- test5 =%5.*d\n", 9, num);
	ft_printf("ft_printf --- test5 =%5.*d\n", 9, num);
	printf("printf    --- test6 =%10.*d\n", 7, -126);
	ft_printf("ft_printf --- test6 =%10.*d\n", 7, -126);
	printf("printf    --- test7 =%-15.*d\n", 4, num);
	ft_printf("ft_printf --- test7 =%-15.*d\n", 4, num);
	printf("printf    --- test8 =%-*.*d\n", 10,0, 0);
	ft_printf("ft_printf --- test8 =%-*.*d\n", 10, 0, 0);
	printf("printf    --- test8 =%-10.0d\n", 0);
	ft_printf("ft_printf --- test8 =%-10.0d\n", 0);


	printf("\n--------------------TEST OUTPUT UNSIGN------------------\n\n");
	printf("printf    --- test1 %%%%%% =%---*u text%.u\n", 20, unum, unum);
	ft_printf("ft_printf --- test1 %%%%%% =%---*u text%.u\n", 20, unum, unum);
	printf("printf    --- test3 %%%%%% =%*.15u text\n", 20, unum);
	ft_printf("ft_printf --- test3 %%%%%% =%*.15u text\n", 20, unum);

	printf("printf    --- test4 %%%%%% =%20.u text%.*u\n", unum, 20, unum);
	ft_printf("ft_printf --- test4 %%%%%% =%20.u text%.*u\n", unum, 20,unum);
	printf("\nprintf    --- test1 %%%%%% =%.*x text\n", 75,  unum);
	ft_printf("ft_printf --- test1 %%%%%% =%.*x text\n", 75, unum);
	printf("printf    --- test1 %%%%%% =%*.15X text\n", 20, unum);
	ft_printf("ft_printf --- test1 %%%%%% =%*.15X text\n", 20, unum);
	printf("printf    --- test1 %%%%%% =%*X text\n", 20, num);
	ft_printf("ft_printf --- test1 %%%%%% =%*X text\n", 20, num);
	printf("printf    --- test1 %%%%%% =%*X text\n", 20, 0);
	ft_printf("ft_printf --- test1 %%%%%% =%*X text\n", 20, 0);

	printf("\n--------------------TEST OUTPUT POINTER------------------\n\n");
	printf("printf    --- test1 %%%%%% =%*p text\n", 20, p);
	ft_printf("ft_printf --- test1 %%%%%% =%*p text\n", 20, p);
	printf("printf    --- test1 %%%%%% =%---*p text\n", 20, pc);
	ft_printf("ft_printf --- test1 %%%%%% =%---*p text\n", 20, pc);
	printf("printf    --- test1 %%%%%% =%30p text\n", &p);
	ft_printf("ft_printf --- test1 %%%%%% =%30p text\n", &p);
	printf("printf    --- test1 %%%%%% =%--30p text\n", ps);

	ft_printf("ft_printf --- test1 %%%%%% =%--30p text\n", ps);


	printf("\n--------------------TEST OUTPUT LEN------------------\n\n");
	printf("len = %d\n", printf("printf    --- test1 %%%%%% =%--30p text\n",
								ps));
	printf("len = %d\n", ft_printf("ft_printf --- test1 %%%%%% =%--30p "
								"text\n", ps));
	printf("len = %d\n", printf("printf    --- test5 =%--c param1 %%%%%%%% "
								"=%10c param2\n", c, c));
	printf("len = %d\n", ft_printf("ft_printf --- test5 =%--c param1 %%%%%%%% =%10c param2\n", c, c));
	printf("len = %d\n", printf("printf    --- test1 %%%%%% =%---*p text\n",
								20, pc));
	printf("len = %d\n", ft_printf("ft_printf --- test1 %%%%%% =%---*p "
								   "text\n", 20, pc));
	printf("len = %d\n", printf("printf    --- test2 %%%%%% =%u text\n",
								unum));
	printf("len = %d\n", ft_printf("ft_printf --- test2 %%%%%% =%u text\n",
								   unum));
	printf("len = %d\n", printf("printf    --- test8 =%*.*d param1 =%5.*s param2 =%-*.*s "
								"param3\n",15,	6, num, 4, "HelloWold", 10, 5, "HelloWorld"));
	printf("len = %d\n", ft_printf("ft_printf --- test8 =%*.*d param1 =%5.*s param2 =%-*.*s param3\n", 15, 6, num,  4,
								   "HelloWold", 10, 5, "HelloWorld"));
	printf("len = %d\n", printf("printf    --- test9 %%%%%% =%---*.30d "
								"text\n", 15, -2147483647));
	printf("len = %d\n", ft_printf("ft_printf --- test9 %%%%%% =%---*.30d "
								   "text\n", 15, -2147483647));

	printf("\n--------------------TEST RETRY------------------\n\n");
	printf(" --- Return : %d\n", printf("%i, %d, %d, %d, %d, %d, %u, %x, %X", 0, 0, 0, 0, 0, 0, 0, 0, 0));
	printf(" --- Return : %d\n", ft_printf("%i, %d, %d, %d, %d, %d, %u, %x, "
										 "%X", 0, 0, 0, 0, 0, 0, 0, 0, 0));
	printf(" --- Return : %d\n", printf("%05%"));
	printf(" --- Return : %d\n", ft_printf("%05%"));
	//printf(" --- Return : %d\n", printf("%000s", "hi low"));
	printf(" --- Return : %d\n", ft_printf("%000s", "hi low"));
	//free(tail_str);
	return 0;
}
