// math_d some math functions
// this should be in the mudos don't know
// by fire on July 14, 1999
int my_sqrt_test(int i,int p_min,int p_max) {
	int s_max,s_min,p_mid,s_mid;
	if(p_min==p_max) return p_min;
	if((p_max-p_min)==1) {
		s_max=p_max*p_max;
		s_min=p_min*p_min;
		if((s_max-i)>=(i-s_min)) return p_min;
			return p_max;
	}
	p_mid=(p_min+p_max)/2;
	s_mid=p_mid*p_mid;
	if(s_mid>i) return my_sqrt_test(i,p_min,p_mid);
	if(s_mid<i) return my_sqrt_test(i,p_mid,p_max);
	return p_mid;
}

int sqrt(int i) {
	if(i<=1) return 1;
	if(i<=4096) return my_sqrt_test(i,1,64);
	if(i<=16384) return my_sqrt_test(i,64,128);
	if(i<=36864) return my_sqrt_test(i,128,192);
	if(i<=65536) return my_sqrt_test(i,192,256);
	if(i<=102400) return my_sqrt_test(i,256,320);
	return 320;
}

int anti_line_dis(int p_low,int p_high) {
	int n;
	int tmp,tmp1;
	n=p_high-p_low+4;
	tmp=2*n+1;
	tmp*=tmp;
	tmp1=4*n*(n+1)*random(1000)/1000;
	tmp-=tmp1;
	tmp=sqrt(tmp);
	tmp--;
	tmp/=2;
	tmp=n-tmp+p_low-2;
	tmp=bmax(tmp,p_low);
	tmp=bmin(tmp,p_high);
	return tmp;
}