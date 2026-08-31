<?php require_once("lib/pd.php"); ?>
				<br><br>
There are currently 4 players online.				<br><br>
				<center>
				<table>
					<tr>
						<td width=75></td>
						<td width=100>Name</td>
						<td width=100>Race</td>
						<td width=100>Subclass</td>
						<td width=125>Guild</td>
						<td>Email &nbsp;</td>
						<td>Pic &nbsp;</td>
						<td>Char &nbsp;</td>
					</tr>
					<tr>
						<td colspan=10 align="center"><hr size=1 width="100%"></center></td>
					</tr>
					<tr>
						<td><font color=blue> [Admin ]</font></td>
						<td>Nulvect</td>
						<td>Imp</td>
						<td>Scout</td>
						<td> </td>
						<td><a href='mailto:nulvect@primaldarkness.com'>Yes</a>						<td>
<?php	if(get_player_image("nulvect")) echo("<a href='/players/pictures/nulvect/'>Pic</a>");
?>
						</td>
						<td>
<?php
	if(file_exists("/home/primal/public_html/players/illustrations/nulvect.htm")) echo("<a href='../players/illustrations/nulvect.htm'>Char</a>");
?>
						</td>
					</tr>					<tr>
						<td><font color=magenta> [Immrtl]</font></td>
						<td>Vian</td>
						<td>Demon</td>
						<td>Wizard</td>
						<td> </td>
						<td><a href='mailto:shamash@gmail.com'>Yes</a>						<td>
<?php	if(get_player_image("vian")) echo("<a href='/players/pictures/vian/'>Pic</a>");
?>
						</td>
						<td>
<?php
	if(file_exists("/home/primal/public_html/players/illustrations/vian.htm")) echo("<a href='../players/illustrations/vian.htm'>Char</a>");
?>
						</td>
					</tr>					<tr>
						<td><font color=cyan> [Player]</font></td>
						<td>Moraleo</td>
						<td>Archangel</td>
						<td>Jester</td>
						<td> </td>
						<td></td>						<td>
<?php	if(get_player_image("moraleo")) echo("<a href='/players/pictures/moraleo/'>Pic</a>");
?>
						</td>
						<td>
<?php
	if(file_exists("/home/primal/public_html/players/illustrations/moraleo.htm")) echo("<a href='../players/illustrations/moraleo.htm'>Char</a>");
?>
						</td>
					</tr>					<tr>
						<td><font color=cyan> [Player]</font></td>
						<td>Abraxas</td>
						<td>Dragon</td>
						<td>Blue</td>
						<td>Forsaken</td>
						<td></td>						<td>
<?php	if(get_player_image("abraxas")) echo("<a href='/players/pictures/abraxas/'>Pic</a>");
?>
						</td>
						<td>
<?php
	if(file_exists("/home/primal/public_html/players/illustrations/abraxas.htm")) echo("<a href='../players/illustrations/abraxas.htm'>Char</a>");
?>
						</td>
					</tr></table></center><p><br><center><font size=1>&copy;Primal Darkness<br>Last updated Sun Jul 22 02:26:03 2012</font></center>