// updated by Zjb@TY
string chinese_ty(int i)
{
        if (i < 0)
                return "¸º" + chinese_ty(-i);
        if (i < 11)
                return se_random[k]["yanse"]+c_num[i]+ yanse(k);
        if (i < 20)
                return se_random[k]["yanse"]+c_digit[1] +yanse(k) + c_random[random(20)]+se_random[k]["yanse"]+ c_num[i - 10]+yanse(k);
        if (i < 100) {
                if (i % 10)
                        return se_random[k]["yanse"]+c_num[i / 10] +yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+
c_digit[1] +yanse(k)+ c_random[random(20)]+se_random[k]["yanse"]+ c_num[i % 10] +yanse(k);
                else
                        return se_random[k]["yanse"]+c_num[i / 10] +yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+ c_digit[1]+yanse(k);
        }
        if (i < 1000) {
                if (i % 100 == 0)
                        return se_random[k]["yanse"]+c_num[i/100]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+ c_digit[2]+yanse(k);
                else if (i % 100 < 10)
                        return se_random[k]["yanse"]+c_num[i/100]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+ c_digit[2]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+
                        c_num[0]+yanse(k)+c_random[random(20)]+chinese_ty(i % 100);
                else if (i % 100 < 10)
                        return se_random[k]["yanse"]+c_num[i / 100]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[2]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+
                        c_num[1]+yanse(k)+c_random[random(20)]+chinese_ty(i % 100);
                else
                        return se_random[k]["yanse"]+c_num[i / 100]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[2]+yanse(k)+c_random[random(20)]+
                        chinese_ty(i % 100);
        }
        if (i < 10000) {
                if (i % 1000 == 0)
                        return se_random[k]["yanse"]+c_num[i / 1000]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[3]+yanse(k);
                else if (i % 1000 < 100)
                        return se_random[k]["yanse"]+c_num[i / 1000]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[3]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+
                        c_num[0]+yanse(k)+c_random[random(20)]+ chinese_ty(i % 1000);
                else
                        return se_random[k]["yanse"]+c_num[i / 1000]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[3]+yanse(k)+c_random[random(20)]+
                        chinese_ty(i % 1000);
        }
        if (i < 100000000) {
                if (i % 10000 == 0)
                        return chinese_ty(i / 10000)+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+ c_digit[4]+yanse(k);
                else if (i % 10000 < 1000)
                        return chinese_ty(i / 10000)+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+ c_digit[4]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+
                        c_num[0]+yanse(k)+c_random[random(20)]+ chinese_ty(i % 10000);
                else
                        return chinese_ty(i / 10000)+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[4]+yanse(k)+c_random[random(20)]+
                        chinese_ty(i % 10000);
        }
        if (i < 1000000000000) {
                if (i % 100000000 == 0)
                        return chinese_ty(i / 100000000)+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+ c_digit[5]+yanse(k);
                else if (i % 100000000 < 1000000)
                        return chinese_ty(i / 100000000)+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[5]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+
                        c_num[0]+yanse(k)+c_random[random(20)]+chinese_ty(i % 100000000);
                else
                        return chinese_ty(i / 100000000)+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[5]+yanse(k)+c_random[random(20)]+
                        chinese_ty(i % 100000000);
        }
        if (i % 1000000000000 == 0)
                return chinese_ty(i / 1000000000000)+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[6]+yanse(k);
        else if (i % 1000000000000 < 100000000)
                return chinese_ty(i / 1000000000000)+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[6]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+
                c_num[0]+yanse(k)+c_random[random(20)]+ chinese_ty(i % 1000000000000);
        else
                return chinese_ty(i / 1000000000000)+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[6]+yanse(k)+c_random[random(20)]+
                chinese_ty(i % 1000000000000);
}

