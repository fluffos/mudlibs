// Cgi program for watching map of SG
// By flee@sgz 04121999
#include <mudlib.h>
#include <daemons.h>

string main(string arg)
{
	int i, j;
	string html, map, line;
	string *city, *lines;

        html=@HTML
<html><body background="http://sgz.yesite.com/images/desk5.gif" text="#ffffff" link=yellow vlink=yellow alink=yellow>
HTML;
	city = AREA_D->list_areas();

	if( !arg || !stringp(arg) || arg == "" ){
		j = 0;
		html = html + "<head><center><h2>三国志城市地图</h2></center></head>";
		html = html + "<center><h3><table border=5><tr>";
		for( i = 0; i < sizeof(city); i++ ){
			html = html + sprintf("<th><a href=\"/cgi/sg_map.cgi?=%s\">%s</a></td>", city[i], AREA_D->get_area(city[i], "name"));
			if( j == 6 ){
				j = 0;
				html = html + "</tr><tr>";
			} else j++;
		};
		html = html + "</tr></table></h3></center>";
	} else if( member_array(arg, city) == -1 ){
			html = html + @NOFOUND
<br><br><br>
<center><h2>
三国志中没有这个城市或此城市的地图尚未完成。
</h2></center><br><br><br>
NOFOUND;
	} else {
		html = html + sprintf("<head><center><h2>三国志城市战场地图--%s</h2></center></head>", AREA_D->get_area(arg, "name"));
		html = html + "<center><table border=5>";
		html = html + "<tr><th>当前时辰</td><th>当地天气</td><th>当地风向</td></tr>";
		html = html + "<tr><th>" + DAY_D->query_string_hour() + "</td>"
			    + "<th>" + DAY_D->get_weather_short(AREA_D->get_area(arg,"weather")) + "</td>"
			    + "<th>" + DAY_D->get_wind_short(AREA_D->get_area(arg,"wind")) + "</td></tr></table></center>";

		map = MAP_D->preview_city(arg);
		lines = explode(map, "\n");
		lines = lines[2..(sizeof(lines)-6)];

		html = html + "<br><center><table border=0 cellspacing=0 CELLPADDING=%100 bgcolor=000000 font color=ffffff>";

		for( i = 0; i < sizeof(lines); i++){
			line = lines[i];

			line = replace_string(line, "%^GREEN%^", "<font color=7fff00>");
			line = replace_string(line, "%^H_BLUE%^", "<font color=0000FF>");
			line = replace_string(line, "%^H_MAGENTA%^", "<font color=ff00ff>");
			line = replace_string(line, "%^H_YELLOW%^", "<font color=FFFF00>");
			line = replace_string(line, "%^YELLOW%^", "<font color=FFFF00>");
			line = replace_string(line, "%^RESET%^", "<font color=ffffff>");
			line = replace_string(line, "%^H_WHITE%^", "<font color=FFFFFF>");
			line = replace_string(line, "%^H_RED%^", "<font color=FF0000>");
			line = replace_string(line, "%^H_GREEN%^", "<font color=00FF00>");
			line = "<font color=ffffff>" + line;

			html = html + "<tr><th>" + line + "</td></tr>";
		};
		html = html + "</table></center><br><br>";
	};

	html = html + @END
</body>
</html>
END;

	return html;
}
