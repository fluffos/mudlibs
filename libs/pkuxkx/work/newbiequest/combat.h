//combat.c
//战斗相关系数和比值计算函数

//战斗系数，仅支持对经验值和技能进行计算，技能取立方，经验直接取
//flag 0--经验，1--技能
int combat_coef(int index, int flag)
{
  float f_ind,result,buf;
  int fhao;

  f_ind=to_float(index);
  if(index<0) {
  	fhao=-1;
  	f_ind=(-1)*f_ind;
  }
  else
  	fhao=1;

  if(flag)
  	f_ind=f_ind*f_ind*f_ind/10;
  
  result=500;
  if(f_ind>1)
  	result=log(f_ind)*1000;
  
  if(f_ind>10000) {
  	buf=log(f_ind/10000);
  	result+=pow(buf,2)*1100;
  }
  
  if(f_ind>100000) {
  	buf=log(f_ind/100000);
  	result+=pow(buf,2.5)*1200;
  }
  	
  if(f_ind>1000000) {
  	buf=log(f_ind/1000000);
  	result+=pow(buf,3)*1300;
  }

  if(f_ind>10000000) {
  	buf=log(f_ind/10000000);
  	result+=pow(buf,3.5)*1400;
  }
  
  return to_int(ceil(result))*fhao;
}

//输入战斗系数1，战斗系数2，根据战斗系数1/战斗系数2的比值，并将比值
//通过数学运算约束到0-1.57之间，1：1的时候值为0.9
//adj_coef为调节系数，调节系数从-1000到1000之间，1000值对应100%，
//调节系数小于0，对战斗系数2进行按比例加大，调节系数大于2，对战斗系数1
//按比例加大。
//返回值为0和1，1表示几率计算命中，0表示几率未抽中
int combat_ratio(int combat_coef1, int combat_coef2, int adj_coef)
{
	int adjCoef;
	float ratio,batCoef1,batCoef2;

//战斗系数输入值为0或者负值就取为1	
	if(combat_coef1<=0)
		batCoef1=1;
	else
		batCoef1=to_float(combat_coef1);
	
	if(combat_coef2<=0)
		batCoef2=1;
	else
		batCoef2=to_float(combat_coef2);

//将调节系数固定在-1000到1000范围内
  if(adj_coef>1000)
  	adjCoef=1000;
  else if(adj_coef<-1000)
  	adjCoef=-1000;
  else
  	adjCoef=adj_coef;

//根据调节系数对战斗系数进行调节
  if(adjCoef>0)
  	batCoef1=batCoef1*(1000+adjCoef)/1000;
  else if(adjCoef<0)
  	batCoef2=batCoef2*(1000-adjCoef)/1000;

//将比值固定在0到1.57的范围内，并且对于战斗系数1比战斗系数2大的时候进行一定程度拉升，以提高比值较低的时候数值变化幅度
	if(batCoef1>batCoef2&&
		 batCoef1<=batCoef2*1.5)
		ratio=0.92+(1-batCoef2/batCoef1);	
	else if(batCoef1>batCoef2*1.5)
		ratio=1.25+(0.67-batCoef2/batCoef1)*0.4776;
	else
		ratio=(batCoef1/batCoef2)*0.92;

//比值趋小的时候坡度不够，比值趋大的时候比值收敛到1的速率不够快
  ratio=pow(sin(ratio),3)*1000;
//	return to_int(ceil(ratio));
	return random(100000)%1000<to_int(ceil(ratio));
}

int t_combat_ratio(int combat_coef1, int combat_coef2, int adj_coef)
{
	int adjCoef;
	float ratio,batCoef1,batCoef2;
  
  printf("%d,%d\n",combat_coef1,combat_coef2);
  
//战斗系数输入值为0或者负值就取为1	
	if(combat_coef1<=0)
		batCoef1=1;
	else
		batCoef1=to_float(combat_coef1);
	
	if(combat_coef2<=0)
		batCoef2=1;
	else
		batCoef2=to_float(combat_coef2);

//将调节系数固定在-1000到1000范围内
  if(adj_coef>1000)
  	adjCoef=1000;
  else if(adj_coef<-1000)
  	adjCoef=-1000;
  else
  	adjCoef=adj_coef;

//根据调节系数对战斗系数进行调节
  if(adjCoef>0)
  	batCoef1=batCoef1*(1000+adjCoef)/1000;
  else if(adjCoef<0)
  	batCoef2=batCoef2*(1000-adjCoef)/1000;

//将比值固定在0到1.57的范围内，并且对于战斗系数1比战斗系数2大的时候进行一定程度拉升，以提高比值较低的时候数值变化幅度
	if(batCoef1>batCoef2&&
		 batCoef1<=batCoef2*1.5)
		ratio=0.92+(1-batCoef2/batCoef1);	
	else if(batCoef1>batCoef2*1.5)
		ratio=1.25+(0.67-batCoef2/batCoef1)*0.4776;
	else
		ratio=(batCoef1/batCoef2)*0.92;

//比值趋小的时候坡度不够，比值趋大的时候比值收敛到1的速率不够快
  ratio=pow(sin(ratio),3)*1000;
//	return to_int(ceil(ratio));
	return to_int(ceil(ratio));
}