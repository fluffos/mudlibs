nosave string *c_num = ({"0","1","2","3","4","5","6","7","8","9","10"});

string tostring(int i)
{	
	
        if (i < 0)
                return "-" + tostring(-i);
        if (i < 11)
                return c_num[i];
        if (i < 20)
                return c_num[1] + c_num[i - 10];
        if (i < 100) {
                if (i % 10)
                        return c_num[i / 10] + c_num[i % 10];
                else
                        return c_num[i / 10] + "0";
        }
        if (i < 1000) {
                if (i % 100 == 0)
                        return c_num[i / 100] + "00";
                else if (i % 100 < 10)
                        return c_num[i / 100] + c_num[0] + tostring(i % 100);
                else
                        return c_num[i / 100] + tostring(i % 100);
        }
        if (i < 10000) {
                if (i % 1000 == 0)
                        return c_num[i / 1000] + "000";
                else if (i % 1000 < 100)
                        return c_num[i / 1000] + c_num[0] + tostring(i % 1000);
                else 
                        return c_num[i / 1000] + tostring(i % 1000);
        }
        if (i < 100000000) {
                if (i % 10000 == 0)
                        return tostring(i / 10000) + "0000";
                else if (i % 10000 < 1000)
                        return tostring(i / 10000) + c_num[0] + tostring(i % 10000);
                else
                        return tostring(i / 10000) + tostring(i % 10000);
        }
        if (i < 1000000000000) {
                if (i % 100000000 == 0)
                        return tostring(i / 100000000) + "0000";
                else if (i % 100000000 < 1000000)
                        return tostring(i / 100000000) + c_num[0] + tostring(i % 100000000);
                else 
                        return tostring(i / 100000000) + tostring(i % 100000000);
        }
        if (i % 1000000000000 == 0)
                return tostring(i / 1000000000000) + "000000000000";
        else if (i % 1000000000000 < 100000000)
                return tostring(i / 1000000000000) + "0000" + tostring(i % 1000000000000);
        else
                return tostring(i / 1000000000000) + tostring(i % 1000000000000);
}
