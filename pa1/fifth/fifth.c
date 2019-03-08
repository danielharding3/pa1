#include <stdio.h>



int main(int argc, char **argv) {
	
	int x = 0;
	char ptr = argv[1][0];
	
	while (ptr != 0) {
	
	if (ptr == 'a' || ptr == 'e' || ptr == 'i' || ptr == 'o' || ptr == 'u'
	|| 	ptr == 'A' || ptr == 'E' || ptr == 'I' || ptr == 'O' || ptr == 'U' ) {
		
		printf("%c", ptr);
	}
	
	x++;
	ptr = argv[1][x];
}
	
	
return 0;
}
