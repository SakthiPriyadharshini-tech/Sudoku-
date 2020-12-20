float poly(float a[], int deg, float x)
{
	float p;
	int i;

	p = a[deg];

	for(i=deg;i>=1;i--)
	{
		p = (a[i-1] + x*p);
	}

	return p;
}
float deriv(float a[], int deg, float x)
{
	float d[10], p = 0,y;
	int i;

	for(i=0;i<=deg;i++)
	{
		y = pow(x, deg-(i+1));
		d[i] = (deg-i)*a[deg-i]*y;
		p = p + d[i];
	}

	return p;
}
