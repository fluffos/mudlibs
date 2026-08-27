/* Tyrael's dos2unix */
#include <stdio.h>

void dos2unix(char *);

int main(int argc, char **argv)
{
	argc--, argv++;
	
	if (!argc) {
		fprintf(stderr, "Nombre de archivo?\n");
		exit(1);
	}
	
	while (argc--)
		dos2unix(*argv++);
	
	exit(0);
}

void dos2unix(char *f)
{
	int y, i = 0, j = 0;
	FILE *fp, *out;
	char buffer[10000000];
	
	if (!(fp = fopen(f, "r"))) {
		fprintf(stderr, "%s no se puede abrir para lectura\n", f);
		return;
	}
	
	if (!(out = fopen(f, "w"))) {
		fprintf(stderr, "%s no se puede abrir para escritura\n", f);
		return;
	}
	
	while ((y = fgetc(fp)) != EOF) {
		if ((char) y == '\r')
			continue;
		buffer[i++] = (char) y;
	}

	printf("len %d\n", i);

	fclose(fp);

	for (; j < i; j++)
		fputc(buffer[j], out);

	fclose(out);
	
	fprintf(stdout, "%s dos2unix'ed\n", f);
	
	return;
}