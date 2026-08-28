/* Majik 4 server
 * Copyright (C) 1998, 1999  Majik Development Team <majik@majik.netti.fi>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <time.h>
#include <weather.h>

/* Global variables */

mixed *humidity, *temperature, *pressure, *state;
mixed *wind_str, *wind_dir;
int TX, TY;

/* Function prototypes */

void changeWeather ();
mixed switchCoordinate (int);
int query_pressure (int, int);
string query_wind_dir_desc (int, int);

void
tell_zone (int x, int y, string str)
{
   object o, env, *all;
   
   all = users();
   
   foreach (o in all)
	 {
		env = ENV(o);
		
		if (env &&
			env->query_outdoors(o->query_gridx(), o->query_gridy()) > 1 &&
			env->query_weather_zone()[0] == x &&
			env->query_weather_zone()[1] == y)
		  {
			 message (CMD_SEE, 0, 0, 0, str, o);
		  }
	 }
}

public void
initializeWeather () 
{
   int i;
   humidity=allocate(ZONES);
   pressure=allocate(ZONES);
   temperature=allocate(ZONES);
   wind_str=allocate(ZONES);
   wind_dir=allocate(ZONES);
   state=allocate(ZONES);
   
   for (i=0;i<ZONES;i++)
	 {
		humidity[i]=allocate(ZONES);
		pressure[i]=allocate(ZONES);
		temperature[i]=allocate(ZONES);
		wind_str[i]=allocate(ZONES);
		wind_dir[i]=allocate(ZONES);
		state[i]=allocate(ZONES);
	 }
   for(i=0;i<=1;i++)
	 {
		humidity[i]=allocate(ZONES);
		pressure[i]=allocate(ZONES);
		temperature[i]=allocate(ZONES);
		wind_str[i]=allocate(ZONES);
		wind_dir[i]=allocate(ZONES);
		state[i]=allocate(ZONES);
	 }
}

void
initializeWeatherData ()
{
   int i, j;
   for(i=0;i<ZONES;i++)
	 for(j=0;j<ZONES;j++)
	 {
	    humidity[i][j]=40 + random(10) + j*4;
	    pressure[i][j]=40 + random(20);
	    temperature[i][j]=j*3 + random(5);
	    wind_str[i][j]=0;
	    wind_dir[i][j]=0;
	 }
}

void
create ()
{
   initializeWeather();
   initializeWeatherData();
   
   restore_object (base_name(THOB));
   changeWeather();
}

mixed
getCoordinate (int x, int y)
{
   if(x<0)
	 x=x+ZONES;
   else
	 if(x>ZONES-1)
	   x=x-ZONES;
   if(y<0)
	 y=y+ZONES;
   else
	 if(y>ZONES-1)
	   y=y-ZONES;
   return ({x,y});
}

private int
getXCoordinate (int x)
{
   if(x<0)
	 x=x+ZONES;
   else
	 if(x>ZONES-1)
	   x=x-ZONES;
   return x;
}

private int
getYCoordinate (int y)
{
   if(y<0)
	 y=y+ZONES;
   else
	 if(y>ZONES-1)
	   y=y-ZONES;
   return y;
}

public void
changeTemperature (int x, int y, int change)
{  
   int tmp;
   int *dat;
   
   dat=getCoordinate(x,y);
   x=dat[0];
   y=dat[1];
   tmp=temperature[x][y]+
	 temperature[getXCoordinate(x-1)][y]+
	 temperature[getXCoordinate(x+1)][y]+
	 temperature[x][getYCoordinate(y-1)]+
	 temperature[x][getYCoordinate(y+1)];
   
   tmp=tmp/5+random(T_CHANGE)-T_CHANGE/2+change;
   tmp=(int)tmp;
   temperature[x][y]=tmp;
}

mixed
switchCoordinate (int dr)
{
   if(dr<0||dr>7)
	 return ({0,0});
   
   switch (dr)
	 {
	  case 0:
		return ({1,0});
	  case 1:
		return ({1,1});
	  case 2:
		return ({0,1});
	  case 3:
		return ({-1,1});
	  case 4:
		return ({-1,0});
	  case 5:
		return ({-1,-1});
	  case 6:
		return ({0,-1});
	  case 7:
		return ({1,-1});
	 }
}

void
determine_wind (int x, int y)
{
   int *dat, tx, ty, i, highest, lowest, tmp, low_dir, high_dir;
   int dr;
   dat=getCoordinate(x,y);
   x=dat[0];
   y=dat[1];
   highest=-1;
   lowest=101;
   for (i=0;i<8;i++)
	 {
		tx=x;
		ty=y;
		dat=switchCoordinate(i);
		tx+=dat[0];
		ty+=dat[1];
		tmp=query_pressure(tx,ty);
		if(tmp<lowest)
		  {
			 lowest=tmp;
			 low_dir=i;
		  }
		if(tmp>highest)
		  {
			 highest=tmp;
			 high_dir=i;
		  }
	 }
   if(highest==lowest)
	 {
		wind_str[x][y]=0;
		wind_dir[x][y]=0;
	 }
   if(high_dir==0)
	 {
		switch (low_dir)
		  {
		   case 1:
			 dr=4;
			 break;
		   case 2:
			 dr=6;
			 break;
		   case 3:
			 dr=7;
			 break;
		   case 4:
			 dr=8;
			 break;
		   case 5:
			 dr=9;
			 break;
		   case 6:
			 dr=10;
			 break;
		   case 7:
			 dr=14;
			 break;
		  }
	 }
   else
	 if(high_dir==1)
	 {
		switch (low_dir)
		  {
		   case 0:
		   case 7:
			 dr=14;
			 break;
		   case 2..3:
			 dr=8;
			 break;
		   case 4:
			 dr=9;
			 break;
		   case 5:
			 dr=10;
			 break;
		   case 6:
			 dr=13;
			 break;
		  }
	 }
   else
	 if(high_dir==2)
	 {
		switch (low_dir)
		  {
		   case 0:
			 dr=14;
			 break;
		   case 1:
			 dr=0;
			 break;
		   case 3:
			 dr=8;
			 break;
		   case 4:
			 dr=10;
			 break;
		   case 5:
			 dr=11;
			 break;
		   case 6:
			 dr=12;
			 break;
		   case 7:
			 dr=13;
			 break;
		  }
	 }
   else
	 if(high_dir==3)
	 {
		switch (low_dir)
		  {
		   case 0:
			 dr=15;
			 break;
		   case 1..2:
			 dr=0;
			 break;
		   case 4..5:
			 dr=12;
			 break;
		   case 6:
			 dr=13;
			 break;
		   case 7:
			 dr=14;
			 break;
		  }
	 }
   else
	 if(high_dir==4)
	 {
		switch (low_dir)
		  {
		   case 0:
			 dr=0;
			 break;
		   case 1:
			 dr=1;
			 break;
		   case 2:
			 dr=2;
			 break;
		   case 3:
			 dr=4;
			 break;
		   case 5:
			 dr=12;
			 break;
		   case 6:
			 dr=14;
			 break;
		   case 7:
			 dr=15;
			 break;
		  }
	 }
   else
    if(high_dir==5)
    {
	   switch (low_dir)
		 {
		  case 0:
			dr=1;
			break;
		  case 1:
			dr=2;
			break;
		  case 2:
			dr=3;
			break;
		  case 3..4:
			dr=4;
			break;
		  case 6..7:
			dr=0;
			break;
		 }
    }
   else
	 if(high_dir==6)
	 {
		switch (low_dir)
		  {
		   case 0:
			 dr=2;
			 break;
		   case 1:
			 dr=3;
			 break;
		   case 2:
			 dr=4;
			 break;
		   case 3:
			 dr=5;
			 break;
		   case 4:
			 dr=6;
			 break;
		   case 5:
			 dr=8;
			 break;
		   case 7:
			 dr=0;
			 break;
		  }
	 }
   else
	 if(high_dir==7)
	 {
		switch (low_dir)
		  {
		   case 0..1:
			 dr=4;
			 break;
		   case 2:
			 dr=5;
			 break;
		   case 3:
			 dr=6;
			 break;
		   case 4:
			 dr=7;
			 break;
		   case 5..6:
			 dr=8;
			 break;
		  }
	 }
   wind_dir[x][y]=dr;
   wind_str[x][y]=highest-lowest;
}

private void
modify_pressure (int x, int y, int change)
{
   int *dat;
   dat=getCoordinate(x,y);
   x=dat[0];
   y=dat[1];
   pressure[x][y]=pressure[x][y]+change;
}

public void
changePressure (int x, int y, int change)
{
   int tx, ty, i, p1, avg;
   int *dat;
   
   dat=getCoordinate(x,y);
   x=dat[0];
   y=dat[1];
   p1=0;
   
   avg=0;
   for (i=0;i<8;i++)
	 {
		tx=x;
		ty=y;
		dat=switchCoordinate(i);
		tx+=dat[0];
		ty+=dat[1];
		avg+=query_pressure(tx,ty);
	 }
   avg+=query_pressure(x,y);
   avg=(int)(avg/9);
   
   p1=random(P_CHANGE)-P_CHANGE/2;
   pressure[x][y]=avg+p1;
   
   for(i=0;i<8;i++)
	 {
		tx=x;
		ty=y;
		dat=switchCoordinate(i);
		tx+=dat[0];
		ty+=dat[1];
		determine_wind(tx,ty);
	 }
   determine_wind(x,y);
}

public void
changeHumidity (int x, int y, int change)
{
   int tmp;
   int *dat;
   
   dat=getCoordinate(x,y);
   x=dat[0];
   y=dat[1];
   
   tmp=humidity[x][y]+
	 humidity[getXCoordinate(x-1)][y]+
	 humidity[getXCoordinate(x+1)][y]+
	 humidity[x][getYCoordinate(y-1)]+
	 humidity[x][getYCoordinate(y+1)];
   
   tmp=tmp/5+random(H_CHANGE)-H_CHANGE/2+change;
   tmp=(int)tmp;
   humidity[x][y]=tmp;
   
}

void
changeWeather ()
{
   int cloud;
   
   save_object (base_name(THOB));
   remove_call_out("changeWeather");
   TY++;
   if(TY>=ZONES)
	 {
		TY=0;
		TX++;
		if(TX>=ZONES)
		  TX=0;
	 }
   
   cloud = THOB->query_cloud_cover();
   
   changePressure(TX,TY,0);
   changeTemperature(TX,TY,0);
   changeHumidity(TX,TY,0);
   
   call_out("changeWeather",(GAME_DAY/(ZONES*ZONES*WCTIMES))/2);
   
   if (cloud == 0 && THOB->query_cloud_cover() == 1)
	 {
		tell_zone(TX, TY, "The sky starts to get cloudy.");
		return;
	 }
   
   if (cloud == 1 && THOB->query_cloud_cover() == 2)
	 {
		tell_zone(TX, TY, "The cloud cover increases.");
		return;
	 }
   
   if (cloud == 2 && THOB->query_cloud_cover() == 3)
	 {
		tell_zone(TX, TY, "The cloud cover increases.");
		return;
	 }
   
   if (cloud == 3 && THOB->query_cloud_cover() == 4)
	 {
		tell_zone(TX, TY, "The sky is now overcast.");
		return;
	 }
   
   if (cloud == 4 && THOB->query_cloud_cover() == 3)
	 {
		tell_zone(TX, TY, "The sky is no longer overcast.");
		return;
	 }
   
   if (cloud == 3 && THOB->query_cloud_cover() == 2)
	 {
		tell_zone(TX, TY, "The cloud cover decreases.");
		return;
	 }
   
   if (cloud == 2 && THOB->query_cloud_cover() == 1)
	 {
		tell_zone(TX, TY, "The cloud cover decreases.");
		return;
	 }
   
   if (cloud == 1 && THOB->query_cloud_cover() == 0)
	 {
		tell_zone(TX, TY, "The clouds disappear.");
		return;
	 }
   
   if (state[TX][TY] == SKY_NOTHING && THOB->query_cloud_cover() > 1)
	 {
		if (random(1000) < (pressure[TX][TY] + humidity[TX][TY]))
		  {
			 state[TX][TY] = SKY_RAINING;
			 if (THOB->query_temperature(TX, TY) < 0)
			   tell_zone (TX, TY, "It starts to snow.");
			 else if (THOB->query_temperature(TX, TY) < 5)
			   tell_zone (TX, TY, "It starts to sleet.");
			 else if (THOB->query_temperature(TX, TY) < 10)
			   tell_zone (TX, TY, "It starts to hail.");
			 else
			   tell_zone (TX, TY, "It starts to rain.");
			 
			 return;
		  }
	 }
   
   if (state[TX][TY] == SKY_RAINING && THOB->query_cloud_cover() > 2)
	 {
		if (random(1000) < (pressure[TX][TY] + humidity[TX][TY]))
		  {
			 state[TX][TY] = SKY_LIGHTNING;
			 tell_zone (TX, TY, "Lightning starts to show in the sky.");
			 return;
		  }
	 }
   
   if (state[TX][TY] == SKY_LIGHTNING && !random(10))
	 {
		state[TX][TY] = SKY_RAINING;
		tell_zone (TX, TY, "The lightning stops.");
		return;
	 }
   
   if (state[TX][TY] == SKY_RAINING && !random(10))
	 {
		state[TX][TY] = SKY_NOTHING;
		
		if (THOB->query_temperature(TX, TY) < 0)
		  tell_zone (TX, TY, "The snow stops.");
		else if (THOB->query_temperature(TX, TY) < 5)
		  tell_zone (TX, TY, "The sleet stops.");
		else if (THOB->query_temperature(TX, TY) < 10)
		  tell_zone (TX, TY, "The hail stops.");
		else
		  tell_zone (TX, TY, "The rain stops.");
		
		return;
	 }
   
   if (state[TX][TY] == SKY_LIGHTNING)
	 {
		tell_zone (TX, TY,
				   ({ "Bolts of lightning are illuminating the vicinity in brief flashes.",
					  "Lightning bolts are chaotically cavorting in the sky.",
					  "Thunder and lightning are raging in the air.",
					  "You hear the clap of distant thunder.",
					  "ZAP! A lightning bolt strikes nearby." })
				   [random(5)]);
		
		return;
	 }
   
   if (state[TX][TY] == SKY_RAINING)
	 {
		if (THOB->query_temperature(TX, TY) < 0)
		  {
			 tell_zone (TX, TY,
						({ "Snow is caressing the skies.",
						   "Snowflakes are dancing whimsically in the air.",
						   "Snowflakes are dressing the ground in white." })
						[random(3)]);
		  }
		else if (THOB->query_temperature(TX, TY) < 5)
		  {
			 tell_zone (TX, TY,
						({ "Sleet is starting to become a nuisance.",
						   "Sleet is slushing places up.",
						   "Rain disguised as snow is discreetly drenching the ground." })
						[random(3)]);
		  }
		else if (THOB->query_temperature(TX, TY) < 10)
		  {
			 tell_zone (TX, TY,
						({ "The clouds are bombarding the ground with hailstones.",
						   "Dropping hailstones are stinging your skin.",
						   "Hail is falling from the sky." })
						[random(3)]);
		  }
		else
		  {
			 tell_zone (TX, TY,
						({ "The gods are sprinkling the ground with rain.",
						   "Drops of rain are making things wet.",
						   "Raindrops are plunging through the air." })
						[random(3)]);
		  }
		
		return;
	 }
   
   if (THOB->query_wind_str(TX, TY) > 50)
	 {
		tell_zone (TX, TY,
				   ({ "The wind is trying to knock you down.",
					  "Surges of wind are aimlessly attacking everything they run into.",
					  "The wind is whistling in your ears." })
				   [random(3)]);
		
		return;
	 }
   
   // 20 x 20 x 4 == 4 sec
   return;
}

int
query_temperature (int x, int y)
{
   int *dat;
   dat=getCoordinate(x,y);
   x=dat[0];
   y=dat[1];
   return temperature[x][y];
}

int
query_pressure (int x, int y)
{
   int *dat;
   dat=getCoordinate(x,y);
   x=dat[0];
   y=dat[1];
   return pressure[x][y];
}

int
query_humidity (int x, int y)
{
   int *dat;
   dat=getCoordinate(x,y);
   x=dat[0];
   y=dat[1];
   return humidity[x][y];
}

int
query_wind_str (int x, int y)
{
   int *dat;
   dat=getCoordinate(x,y);
   x=dat[0];
   y=dat[1];
   return wind_str[x][y];
}

int
query_wind_dir (int x, int y)
{
   int *dat;
   dat=getCoordinate(x,y);
   x=dat[0];
   y=dat[1];
   return wind_dir[x][y];
}

public void
show_humidity ()
{
   int i, j;
   for (i=0;i<ZONES;i++)
	 {
		for(j=0;j<ZONES;j++)
		  write(humidity[i][j]+"  "); 
		write("\n");
	 }
}

public void
show_pressure ()
{
   int i, j;
   for (i=0;i<ZONES;i++)
	 {
		for(j=0;j<ZONES;j++)
		  write(pressure[i][j]+"  ");
		write("\n");
    }
}

public void
show_state_desc ()
{
   int i, j;
   for (i=0;i<ZONES;i++)
	 {
		for (j=0;j<ZONES;j++)
		  {
			 if (state[i][j] == SKY_NOTHING)
			   continue;
			 
			 write ("x"+i+"y"+j+": ");

			 if (state[i][j] == SKY_RAINING)
			   write ("SKY_RAINING\n");
			 else if (state[i][j] == SKY_LIGHTNING)
			   write ("SKY_LIGHTNING\n");
		  }
	 }
}

public void
show_state ()
{
   int i, j;
   
   for (i=0;i<ZONES;i++)
	 {
		for(j=0;j<ZONES;j++)
		  write(state[i][j]+"  ");
		write("\n");
	 }
}   

public void
show_temperature ()
{
   int i, j;
   for(i=0;i<ZONES;i++)
	 {
		for(j=0;j<ZONES;j++)
		  write(temperature[i][j]+"  ");
		write("\n");
	 }
}

public void
show_wind_str ()
{
   int i, j;
   for(i=0;i<ZONES;i++)
	 {
		for(j=0;j<ZONES;j++)
		  write(wind_str[i][j]+"  ");
		write("\n");
    }
}

public void
show_wind_dir ()
{
   int i,j;
   for (i=0;i<ZONES;i++)
	 {
		for(j=0;j<ZONES;j++)
		  write(wind_dir[i][j]+"  ");
		write("\n");
	 }
}

int
query_cloud_cover (int x, int y)
{
   int *dat;
   int h, t, p, cl;
   dat=getCoordinate(x,y);
   x=dat[0];
   y=dat[1];
   h=humidity[x][y];
   t=temperature[x][y];
   p=pressure[x][y];
   cl=0;
   switch (p)
	 {
	  case 0..33:
		cl++;
		break;
	  case 67..100:
		cl++;
		break;
	  default:
		break;
    }
   switch (h)
	 {
	  case 67..100:
		cl=cl+1;
	  case 34..66:
		cl=cl+1;
	  case 0..33:
		cl=cl+1;
	 }
   return cl;
}

string
query_cloud_cover_desc (int x, int y)
{
   int cl;
   
   cl=query_cloud_cover(x,y);
   
   switch (cl)
	 {
	  case 0:
		return "no";
	  case 1:
		return "light";
	  case 2:
		return "medium";
	  case 3:
		return "heavy";
	  case 4:
		return "extreme";
	 }
}

string
query_wind_desc (int x, int y)
{
   string dire;
   int st;
   
   x=getXCoordinate(x);
   y=getYCoordinate(y);
   dire="";
   dire=query_wind_dir_desc(x,y);
   st=query_wind_str(x,y);
   
   switch (st)
	 {
	  case 0:
		return "calm air";
	  case 1..3:
		return "light "+dire+" breeze";
	  case 4..6:
		return "gentle "+dire+" breeze";
	  case 7..10:
		return "moderate "+dire+" breeze";
	  case 11..16:
		return "strong "+dire+" breeze";
	  case 17..21:
		return "gentle "+dire+" wind";
	  case 22..27:
		return "strong "+dire+" wind";
	  case 28..33:
		return "moderate "+dire+" gale";
	  case 34..40:
		return "fresh "+dire+" gale wind";
	  case 41..47:
		return "strong "+dire+" gale wind";
	  case 48..55:
		return "whole "+dire+" gale wind";
	  case 56..63:
		return "weak storm going "+dire;
	  case 64..74:
		return "storm going "+dire;
	  default:
		return "hurricane going "+dire;     
	 }
}
   
string
query_wind_dir_desc (int x, int y)
{
   int dr;
   
   x=getXCoordinate(x);
   y=getYCoordinate(y);
   dr=query_wind_dir(x,y);
   
   switch (dr)
	 {
	  case 0:
		return "east";
	  case 1:
		//	return "east-southeast";
	  case 2:
		return "southeast";
	  case 3:
		//	return "south-southeast";
	  case 4:
		return "south";
	  case 5:
		//	return "south-southwest";
	  case 6:
		return "southwest";
	  case 7:
		//	return "west-southwest";
	  case 8:
		return "west";
	  case 9:
		//	return "west-northwest";
	  case 10:
		return "northwest";
	  case 11:
		//	return "north-northwest";
	  case 12:
		return "north";
	  case 13:
		//	return "north-northeast";
	  case 14:
		return "northeast";
	  case 15:
		//	return "east-northeast";
	 }
}

string
query_weather (int x, int y, int out)
{
   string msg;
   int wd, ws;
   
   wd=query_wind_dir(x,y);
   ws=query_wind_str(x,y);
   
   /* rn=query_rain(x,y); */
   
   msg="";
   if(out<1)
	 return msg;
   if(!ws)
	 {
		if(out>2)
		 msg+=capitalize(query_cloud_cover_desc(x,y))+" clouds hang in the calm air. ";
	 }
   else
	 {
		if(out>2)
		  msg+=capitalize(query_cloud_cover_desc(x,y))+" clouds move in "+
		  query_wind_desc(x,y)+". ";
	 }
   
   if(out==1)
	 {
		msg+=capitalize(query_wind_desc(x,y))+
		  " blows outside. "; 
	 }
   return msg;                 
}

void
do_weather_effects (object who, object room, int x, int y)
{
}
