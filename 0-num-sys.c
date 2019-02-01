#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

main() {
	int Nach, Itog, posl, dot, kz, rz, en, p, lc;
	long long a = 0;
	double b = 0.0;
	char ExB[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	char Chisl[27];
	char Res[67];
	bool prov = true;
	dot = 0;
	for (int k = 0; k < 27; k++)
		Chisl[k] = '!';
	scanf("%d", &Nach);
	scanf("%d", &Itog);
	scanf("%s", &Chisl);
	if ((Nach > 16) || (Nach < 2) || (Itog > 16) || (Itog < 2)) prov = false;
	if (prov) {
		for (int i = 0; i < 26; i++) {
			Chisl[i] = toupper(Chisl[i]);
			if ((Chisl[i] > ExB[Nach - 1])) {
				prov = false;
			}
		}
	}
	int i = 0;
	while ((Chisl[i] != '.') && (Chisl[i] != '!')) {
		i++;
	}
	i = i - 1;
	lc = i;
	for (int e = 0; e < 26; e++) {
		if (Chisl[e] == '.') {
			dot++;
		}
		if (Chisl[e] == '!') {
			kz = e; break;
		}
	}
	if ((dot > 1) || (Chisl[0] == '.')) {
		prov = false;
	}
	if (Chisl[kz - 2] == '.') {
		prov = false;
	}
	if (prov == true) {
		for (int j = 0; j < 67; j++) {
			Res[j] = '!';
		}
		if (dot == 0) {
			i--;
			lc--;
		}
		for (i; i >= 0; i--) {
			if ((int)(Chisl[lc - i]) > 57) {
				rz = 55;
			}
			else {
				rz = 48;
			}
			a = (a + ((int)(Chisl[lc - i]) - rz))*Nach;
		}
		a = a / Nach;
		lc = lc + 2;
		for (i = 0; i < 27; i++) {
			if (Chisl[i] == '!') {
				en = i;
				break;
			}
		}
		for (en; en > lc + 1; en--) {
			if ((int)(Chisl[en - 2] > 57)) {
				rz = 55;
			}
			else {
				rz = 48;
			}
			b = ((b + (int)(Chisl[en - 2]) - rz)) / Nach;
		}
		i = 53;
		Res[i + 1] = '.';
		Res[i] = '0';
		Res[i + 2] = '0';
		while (a > 0) {
			if (a%Itog > 9) {
				rz = 55;
			}
			else {
				rz = 48;
			}
			Res[i] = a % Itog + rz;
			i--;
			a = a / Itog;
		}
		p = 0;
		i = 55;
		if (b == 0.0) posl = 54; else posl = 67;
		while ((b > 0) && (p < 12)) {
			b = b * Itog;
			if ((int)(b) > 9) {
				rz = 55;
			}
			else {
				rz = 48;
			}
			Res[i] = (int)(b)+rz;
			i++;
			p++;
			if (b >= 1.0) {
				b = b - (int)(b);
			}
		}
		for (i = 0; i < posl; i++) {
			if (Res[i] != '!')
				printf("%c", Res[i]);
		}
	}
	else printf("bad input");
	return 0;
}