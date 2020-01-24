int n, temp;
int fact(n)
{
	if (n <= 1) {
		temp = 1;
	} else {
		fact(n - 1);
		temp = temp * n;
	}
	return 0;
}

int main()
{
	printf("%d", n);
	fact(n);
	scanf("%d", &temp);
}
