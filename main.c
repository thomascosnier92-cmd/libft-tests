#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include <limits.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

static char	test_mapi(unsigned int i, char c)
{
	(void)i;
	if (c >= '6')
		return (c + 1);
	return (c);
}

static void	test_iteri(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'C')
		*c += 1;
}

static void	test_lstiter(void *content)
{
	char	*s;
	int		i;

	s = (char *)content;
	i = 0;
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
}

static void	*test_lstmap(void *content)
{
	return (ft_strjoin((char *)content, "!"));
}

int main(void)
{
    printf("    --ATOI TEST--\n\n");
	if (atoi("145") == ft_atoi("145"))
		printf("expected %d, got %d.\n", atoi("145"), ft_atoi("145"));
	else
		printf("Try again: expected %d, got %d.\n", atoi("145"), ft_atoi("145"));
    printf("\n\n");


	char	sft[20] = "ABCDEF";
    printf("    --BZERO TEST--\n\n");
	ft_bzero(sft, 5);
	printf("RESULT [%c] [%c] [%c] [%c] [%c] [%c]\n", sft[0], sft[1], sft[2], sft[3], sft[4], sft[5]);
    printf("\n\n");

	
    printf("    --CALLOC TEST--\n\n");
    int n = 5;
	int *array;

	array = (int *)ft_calloc(n, sizeof(int));
	if (array == NULL)
	{
		printf("Memory allocation failed!\n");
		return (1);
	}

	printf("Array elements after calloc: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	free(array);
    printf("\n\n");

    
    printf("    --ISALNUM TEST--\n\n");
	char a;

	a = '2';
	printf("2 = %d\n", ft_isalnum(a));
	a = 'A';
	printf("A = %d\n", ft_isalnum(a));
	a = 'd';
	printf("d = %d\n", ft_isalnum(a));
	a = '-';
	printf("- = %d\n", ft_isalnum(a));
	printf("\n\n");    


    printf("    --ISALPHA TEST--\n\n");
	char	c;

	c = 'A';
	printf(" %c = %d\n", c, (ft_isalpha(c)));
	c = 'z';
	printf(" %c = %d\n", c, (ft_isalpha(c)));
	c = 'Z';
	printf(" %c = %d\n", c, (ft_isalpha(c)));
	c = 's';
	printf(" %c = %d\n", c, (ft_isalpha(c)));
	c = '3';
	printf(" %c = %d\n", c, (ft_isalpha(c)));
	c = ',';
	printf(" %c = %d\n", c, (ft_isalpha(c)));
	c = 0;
	printf(" %c = %d\n", c, (ft_isalpha(c)));
	c = '`';
	printf(" %c = %d\n", c, (ft_isalpha(c)));
	c = '{';
	printf(" %c = %d\n", c, (ft_isalpha(c)));
    printf("\n\n");


    printf("    --ISASCII TEST--\n\n");

	a = '2';
	printf("2 = %d\n", ft_isascii(a));
	a = 'A';
	printf("A = %d\n", ft_isascii(a));
	a = 'd';
	printf("d = %d\n", ft_isascii(a));
	a = '\n';
	printf("\\n = %d\n", ft_isascii(a));
	printf("\n\n");


    printf("    --ISDIGIT TEST--\n\n");
    int ca;
    ca = '1';
    printf(" %c = %d\n", ca, ft_isdigit(ca));
    ca = '2';
    printf(" %c = %d\n", ca, ft_isdigit(ca));
    ca = '3';
    printf(" %c = %d\n", ca, ft_isdigit(ca));
    printf("\n\n");


    printf("    --ISPRINT TEST--\n\n");
    a = '7';
	printf("7 = %d\n", ft_isprint(a));
	a = 'C';
	printf("C = %d\n", ft_isprint(a));
	a = 'b';
	printf("b = %d\n", ft_isprint(a));
	a = '\n';
	printf("\\n = %d\n", ft_isprint(a));
	printf("\n\n"); 


    printf("    --ITOA TEST--\n\n");
    printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2026-1998));
	printf("%s\n", ft_itoa(8+9));
	printf("%s\n", ft_itoa(-995));
	printf("\n\n");



	printf("    --LSTADDBACK TEST--\n\n");
	t_list	*head, *node_1, *node_2;

	head = malloc(sizeof(t_list));
	node_1 = malloc(sizeof(t_list));
	node_2 = malloc(sizeof(t_list));

	head->content = (void *)"hello";
	node_1->content = (void *)"world";
	node_2->content = (void *)"!";
	head->next = NULL;
	node_1->next = NULL;
	node_2->next = NULL;
	
	ft_lstadd_back(&head, node_1);
	ft_lstadd_back(&head, node_2);

	t_list	*current;
	
	current = head;
	while (current)
	{
		printf("%s\n", (char *)(current->content));
		current = current->next;
	}
	printf("\n\n");


    
	printf("    --LSTADDFRONT TEST--\n\n");

	head = malloc(sizeof(t_list));
	node_1 = malloc(sizeof(t_list));
	node_2 = malloc(sizeof(t_list));

	head->content = (void *)"hello";
	node_1->content = (void *)"world";
	node_2->content = (void *)"!";
	head->next = NULL;
	node_1->next = NULL;
	node_2->next = NULL;
	
	ft_lstadd_front(&head, node_1);
	ft_lstadd_front(&head, node_2);

	
	current = head;
	while (current)
	{
		printf("%s\n", (char *)(current->content));
		current = current->next;
	}
	printf("\n\n");



    printf("    --LSTCLEAR TEST--\n\n");
	t_list	*lclear;

	lclear = ft_lstnew(ft_strdup("one"));
	ft_lstadd_back(&lclear, ft_lstnew(ft_strdup("two")));
	ft_lstadd_back(&lclear, ft_lstnew(ft_strdup("three")));
	printf("Size before clear: %u\n", ft_lstsize(lclear));
	ft_lstclear(&lclear, free);
	if (lclear == NULL)
		printf("List is NULL after clear: OK\n");
	else
		printf("Try again: list should be NULL after clear.\n");
    printf("\n\n");



    printf("    --LSTDELONE TEST--\n\n");
	t_list	*ldel;

	ldel = ft_lstnew(ft_strdup("delete me"));
	printf("Content before delone: %s\n", (char *)ldel->content);
	ft_lstdelone(ldel, free);
	printf("Node deleted (run valgrind to check leaks).\n");
    printf("\n\n");



    printf("    --LSTTITER TEST--\n\n");
	t_list	*liter;

	liter = ft_lstnew(ft_strdup("hello"));
	ft_lstadd_back(&liter, ft_lstnew(ft_strdup("world")));
	ft_lstadd_back(&liter, ft_lstnew(ft_strdup("42")));
	ft_lstiter(liter, test_lstiter);
	current = liter;
	while (current)
	{
		printf("%s\n", (char *)(current->content));
		current = current->next;
	}
	printf("\nEXPECTED : HELLO / WORLD / 42\n");
	ft_lstclear(&liter, free);
    printf("\n\n");



    printf("    --LSTLAST TEST--\n\n");
	t_list	*llast;

	llast = ft_lstnew("first");
	ft_lstadd_back(&llast, ft_lstnew("second"));
	ft_lstadd_back(&llast, ft_lstnew("third"));
	printf("Last element: %s\n", (char *)(ft_lstlast(llast)->content));
	printf("\nEXPECTED : Last element: third\n");
	ft_lstclear(&llast, NULL);
    printf("\n\n");
    


    printf("    --LSTMAP TEST--\n\n");
	t_list	*lmap;
	t_list	*lmap_new;

	lmap = ft_lstnew(ft_strdup("hello"));
	ft_lstadd_back(&lmap, ft_lstnew(ft_strdup("world")));
	ft_lstadd_back(&lmap, ft_lstnew(ft_strdup("42")));
	lmap_new = ft_lstmap(lmap, test_lstmap, free);
	current = lmap_new;
	while (current)
	{
		printf("%s\n", (char *)(current->content));
		current = current->next;
	}
	printf("\nEXPECTED : hello! / world! / 42!\n");
	ft_lstclear(&lmap, free);
	ft_lstclear(&lmap_new, free);
    printf("\n\n");



    printf("    --LSTNEW TEST--\n\n");
	t_list	*lnew;

	lnew = ft_lstnew("hello");
	printf("Content: %s\n", (char *)(lnew->content));
	if (lnew->next == NULL)
		printf("Next is NULL: OK\n");
	else
		printf("Try again: next should be NULL.\n");
	free(lnew);
    printf("\n\n");



    printf("    --LSTSIZE TEST--\n\n");
	t_list	*lsize;

	lsize = NULL;
	printf("Size of empty list: %u (expected 0)\n", ft_lstsize(lsize));
	lsize = ft_lstnew("a");
	ft_lstadd_back(&lsize, ft_lstnew("b"));
	ft_lstadd_back(&lsize, ft_lstnew("c"));
	printf("Size of list: %u (expected 3)\n", ft_lstsize(lsize));
	ft_lstclear(&lsize, NULL);
    printf("\n\n");



    printf("    --MEMCHR TEST--\n\n");
    
    const char	str1[] = "abcdef";
	const char	ch = 'd';
	char		*result;

	result = (char *)ft_memchr(str1, ch, strlen(str1));
	if (result != NULL)
	{
		printf("'%c' found at position %ld\n", ch, result - str1);
	}
	else
	{
		printf("'%c' not found in the string\n", ch);
	}
    printf("\n\n");


    printf("    --MEMCMP TEST--\n\n");


   char strr1[] = "12345678901400345678";
   char str2[] = "1234567";

   int resulta = ft_memcmp(strr1, str2, 10);

   if (resulta < 0) {
		printf("First is less than second.\n");
   } else if (resulta == 0) {
		printf("First is equal to second.\n");
   } else {
		printf("First is greater than second.\n");
   }
	printf("\nEXPECTED : First is greater than second.\n");
    printf("\n\n");
    
    
    printf("    --MEMCPY TEST--\n\n");

	char sstr1[] = "omega";
	char sstr2[sizeof(sstr1)] = "";

	ft_memcpy(sstr2, sstr1, sizeof(sstr1));

	printf("sstr2 after ft_memcpy: ");
	printf("%s",sstr2);
	printf("\n");
    printf("\n\n");


    printf("    --MEMMOVE TEST--\n\n");
	char	mmove[] = "123456789";

	printf("Before : %s\n", mmove);
	ft_memmove(mmove + 2, mmove, 5);
	printf("After  : %s\n", mmove);
	printf("\nEXPECTED : 121234589\n");
    printf("\n\n");


    printf("    --MEMSET TEST--\n\n");
	char	mset[10] = "abcdefghi";

	printf("Before : %s\n", mset);
	ft_memset(mset, 'x', 5);
	printf("After  : %s\n", mset);
	printf("\nEXPECTED : xxxxxfghi\n");
    printf("\n\n");


    printf("    --PUTCHARFD TEST--\n\n");

    ft_putchar_fd('A', 1);
    ft_putchar_fd('b', 1);
    ft_putchar_fd('C', 1);
    ft_putchar_fd('d', 1);
    ft_putchar_fd('E', 1);
    printf("\n\n");



    printf("    --PUTENDLFD TEST--\n\n");
    ft_putendl_fd("YUUUUUUUUUURR", 1);
    printf("\n\n");

    

    printf("    --PUTNBRFD TEST--\n\n");
    ft_putnbr_fd(1234567890, 1);
    printf("\n\n");



    printf("    --PUTSTRFD TEST--\n\n");
	char    testt[] = "OKADAAAAAAAAAA";
	ft_putstr_fd(testt, 1);
    printf("\n\n");


    printf("    --SPLIT TEST--\n\n");
	char	**tab;
	int		k;

	tab = ft_split("hello world 42 school", ' ');
	k = 0;
	while (tab[k])
	{
		printf("[%d] = |%s|\n", k, tab[k]);
		free(tab[k]);
		k++;
	}
	free(tab);
	printf("\nEXPECTED : hello / world / 42 / school\n");
    printf("\n\n");


    printf("    --STRCHR TEST--\n\n");

	const char str[] = "Tutorialspoint";
    const char cha = '.';
    char *ret;
    ret = ft_strchr(str, cha);
    printf("String after |%c| is - |%s|\n", cha, ret);
    printf("\n EXPECTED : String after |.| is - |(null)|\n");
    printf("\n\n");


    printf("    --STRDUP TEST--\n\n");
	char *sttr = "abcdefghijklmnopqrstuvwxyz";
	printf("%s\n", ft_strdup(sttr));
    printf("\n\n");

    
    
    printf("    --JOIN TEST--\n\n");
    printf("%s\n", ft_strjoin("2+2", "=4"));
    printf("\n\n");

    

    printf("    --STRLCAT TEST--\n\n");
	char	dcat[20] = "Hello";
	char	dcat2[8] = "Hello";
	size_t	rcat;

	rcat = ft_strlcat(dcat, ", World!", sizeof(dcat));
	printf("Result : \"%s\" (return : %zu)\n", dcat, rcat);
	printf("EXPECTED : \"Hello, World!\" (return : 13)\n\n");
	rcat = ft_strlcat(dcat2, ", World!", sizeof(dcat2));
	printf("Result : \"%s\" (return : %zu)\n", dcat2, rcat);
	printf("EXPECTED : \"Hello, \" (return : 13)\n");
    printf("\n\n");

    

    printf("    --STRLCPY TEST--\n\n");
	const char *ssrc = "Hello, World!";
	char ddest[14];

	printf("Source string: \"%s\" (Length: %zu)\n", ssrc, strlen(ssrc));
	printf("Destination buffer size: %zu\n\n", sizeof(ddest));

	size_t rresult = ft_strlcpy(ddest, ssrc, sizeof(ddest));

	printf("Copied string in dest: \"%s\"\n", ddest);
	printf("Return value of strlcpy (expected total length): %zu\n", rresult);

	if (rresult >= sizeof(ddest)) {
		printf("Warning: The string was truncated! You needed a buffer of at least %zu bytes.\n", rresult + 1);
	} else {
		printf("Success: The string was copied entirely without truncation.\n");
	}
    printf("\n\n");



    printf("    --STRLEN TEST--\n\n");
	const char al[] = "aaaaabbbbbcccccddddd";
	printf("%zu", ft_strlen(al));
    printf("\n\n");



    printf("    --STRNCMP TEST--\n\n");
	printf("abcdef / abcxyz (n = 3) : %d\n", ft_strncmp("abcdef", "abcxyz", 3));
	printf("EXPECTED : 0\n\n");
	printf("abcdef / abcxyz (n = 4) : %d\n", ft_strncmp("abcdef", "abcxyz", 4));
	printf("EXPECTED : negative number (%d)\n\n", strncmp("abcdef", "abcxyz", 4));
	printf("abcxyz / abcdef (n = 4) : %d\n", ft_strncmp("abcxyz", "abcdef", 4));
	printf("EXPECTED : positive number (%d)\n", strncmp("abcxyz", "abcdef", 4));
    printf("\n\n");



    printf("    --STRNSTR TEST--\n\n");
	const char	*big = "Hello 42 school";
	char		*found;

	found = ft_strnstr(big, "42", 15);
	printf("Search |42| (len 15) : |%s|\n", found);
	printf("EXPECTED : |42 school|\n\n");
	found = ft_strnstr(big, "42", 7);
	printf("Search |42| (len 7)  : |%s|\n", found);
	printf("EXPECTED : |(null)|\n");
    printf("\n\n");



    printf("    --STRRCHR TEST--\n\n");
	const char	strr[] = "Tutorialspoint";
	char		*rchr;

	rchr = ft_strrchr(strr, 'o');
	printf("Last |o| : |%s|\n", rchr);
	printf("EXPECTED : |oint|\n\n");
	rchr = ft_strrchr(strr, '.');
	printf("Last |.| : |%s|\n", rchr);
	printf("EXPECTED : |(null)|\n");
    printf("\n\n");



    printf("    --STRTRIM TEST--\n\n");
	char	*trim;

	trim = ft_strtrim("   xxhello worldxx   ", " x");
	printf("|%s|\n", trim);
	printf("EXPECTED : |hello world|\n");
	free(trim);
    printf("\n\n");



    printf("    --SUBSTR TEST--\n\n");
	char	*sub;

	sub = ft_substr("Hello 42 school", 6, 2);
	printf("|%s|\n", sub);
	printf("EXPECTED : |42|\n\n");
	free(sub);
	sub = ft_substr("Hello 42 school", 100, 5);
	printf("|%s|\n", sub);
	printf("EXPECTED : ||\n");
	free(sub);
    printf("\n\n");



    printf("    --TOLOWER TEST--\n\n");
	a = 'A';
	printf("A = %c\n", ft_tolower(a));
	a = 'z';
	printf("z = %c\n", ft_tolower(a));
	a = '5';
	printf("5 = %c\n", ft_tolower(a));
	a = 'M';
	printf("M = %c\n", ft_tolower(a));
	printf("\n\n");



    printf("    --TOUPPER TEST--\n\n");
	a = 'a';
	printf("a = %c\n", ft_toupper(a));
	a = 'Z';
	printf("Z = %c\n", ft_toupper(a));
	a = '5';
	printf("5 = %c\n", ft_toupper(a));
	a = 'm';
	printf("m = %c\n", ft_toupper(a));
	printf("\n\n");



	char		str_iteri[] = "ABCDEF";
	const char	*str_mapi = "123456789";
	char		*res_mapi;

	printf("=== TEST FT_STRITERI ===\n");
	printf("Avant : %s\n", str_iteri);
	ft_striteri(str_iteri, test_iteri);
	printf("Apres : %s\n\n", str_iteri);

	printf("=== TEST FT_STRMAPI ===\n");
	res_mapi = ft_strmapi(str_mapi, test_mapi);
	if (res_mapi)
	{
		printf("Avant : %s\n", str_mapi);
		printf("Apres : %s\n\n", res_mapi);
		free(res_mapi);
	}
	else
		printf("Erreur d'allocation memoire.\n\n");



        
}