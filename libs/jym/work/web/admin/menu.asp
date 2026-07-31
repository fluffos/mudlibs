<%@ LANGUAGE = VBScript.Encode %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>Kuang5Cms menu</title>
<link href="css_menu.css" rel="stylesheet" type="text/css" />
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
</head>
<%#@~^mQAAAA==@#@&Bx{'{''{'{x'{'x'{'xx{''{x'{''{xx'{@#@&B~P~狂舞游戏网站管理系统@#@&B~P,AhSRV;mxoX 1Wh@#@&v,P^KwHDkTtDcm* T!FO+TZ,P狂舞网络@#@&B{''{xx'{'{'x'xx{'x'{x'{'xx{''xx{'@#@&wB0AAA==^#~@%>
<script language="javascript">


function getObject(objectId) {
 if(document.getElementById && document.getElementById(objectId)) {
 // W3C DOM
 return document.getElementById(objectId);
 }
 else if (document.all && document.all(objectId)) {
 // MSIE 4 DOM
 return document.all(objectId);
 }
 else if (document.layers && document.layers[objectId]) {
 // NN 4 DOM.. note: this won't find nested layers
 return document.layers[objectId];
 }
 else {
 return false;
 }
}

function showHide(objname){
    var obj = getObject(objname);
    if(obj.style.display == "none"){
		obj.style.display = "block";
	}else{
		obj.style.display = "none";
	}
}
</script>
<base target="main">
<body>

<div class="menu">

<dl>
<dt><a href="###" onclick="showHide('items0');" target="_self"><%#@~^FwAAAA==./2Kxk+RSDbO+,J网站信息管理ELAYAAA==^#~@%></a></dt>
<dd id="items0" style="display:block;">
<ul>
<%#@~^zgEAAA==@#@&DnkwKx/RS.kD+~J@!Vr@*@!lP4.+6'B0;CxT*|/nY CkwvPDCDT+OxE:lrUE@*网站信息配置@!zm@*@!zsb@*r@#@&M+k2W	/nRSDrOPJ@!sk@*@!l,4.+6'E3;lULl{CNsrx|\n.cl/2v,YCDTnD'vslbxB@*游戏介绍修改@!JC@*@!zsk@*J@#@&M+/aGxk+RS.rYPr@!sk@*@!mP4DW'E3;C	o*mLm:nVbdDRCkwEPYmDTnY{Bhlbxv@*开区列表管理@!zl@*@!z^k@*r@#@&D/aWU/n SDrY~J@!Vr@*@!lP4.0xB0;mxLl{9Wh	VbdYcldwEPOCMo+DxBslk	v@*游戏下载管理@!Jl@*@!&Vr@*r@#@&DdwKxdnchDrOPE@!^r@*@!C,tM+0{B0;l	oX{mNhr	{4mU3cl/av~YmDT+O'vhmkUB@*汇款方式管理@!zm@*@!&^k@*E@#@&/n4AAA==^#~@%>
</ul>
</dd>
</dl><!-- Item 1 End -->
<!-- Item 4 Strat -->

<dl>
<dt><a href="###" onclick="showHide('items3');" target="_self"><%#@~^GAAAAA==./2Kxk+RSDbO+,J文章&图片管理JWwYAAA==^#~@%></a></dt>
<dd id="items3" style="display:block;">
<ul>
<%#@~^cgEAAA==@#@&DnkwKx/RS.kD+~J@!Vr@*@!lP4.+6'B0;CxT*|xnhdmmN[RmdwEPOCMo+OxE:Ck	v@*增加文章z图片@!Jl@*@!z^k@*E@#@&Dn/aWUdRhMrYPJ@!sr@*@!l,t.+WxE3;l	L*|xnAk{VrdDRC/av,YCMoY'E:mrxE@*修改文章&图片@!Jl@*@!JVk@*E@#@&D+k2Gxk+ch.kOn,J@!Vb@*@!mP4.0'vV!lUolm	+Ak{aVRm/avPDl.oYxvslk	v@*玩家评论管理@!zl@*@!&Vb@*r@#@&DndaWU/ hMkOn,J@!sr@*@!CP4.0xE3!lxT*|dYmY lkwv~DlDTnY{B:mrUB@*文章数据统计@!Jl@*@!&sb@*E@#@&JmUAAA==^#~@%>
  			</ul>
		</dd>
	</dl><!-- Item 4 End -->
<!-- Item 19 Strat -->

<dl>
    <dt><a href="###" onclick="showHide('items18');" target="_self"><%#@~^FwAAAA==./2Kxk+RSDbO+,J游戏商城管理ELAYAAA==^#~@%></a></dt>
    <dd id="items18" style="display:block;">
	<%#@~^ngAAAA==@#@&DnkwKx/RS.kD+~J@!Es@*r@#@&Mn/aWxkn hMkD+~J@!sb@*@!l,4D0xv0ElULl{CNsr	{d4Waooclk2B,YCDT+OxE:lbUB@*商城页面修改@!zm@*@!z^k@*J@#@&.nkwGxknRSDrOPJ@!&!V@*J@#@&id7xSoAAA==^#~@%>
		</dd>
	</dl><!-- Item 19 End -->
<!-- Item 20 Strat -->

<dl>
    <dt><a href="###" onclick="showHide('items19');" target="_self"><%#@~^FQAAAA==./2Kxk+RSDbO+,J系统管理ELAYAAA==^#~@%></a></dt>
    <dd id="items19" style="display:block;">
			<ul>
			<%#@~^fAIAAA==@#@&DnkwKx/RS.kD+~J@!Vr@*@!lP4.+6'B0;CxT*|Y2RCdaB~Ym.oYxvslkUv@*投票调查@!&l@*@!JVr@*J@#@&D/aGxk+ hMkOn,J@!^r@*@!lP4.n0{B0ECxLX|Vrx0 lkwv~DlDLnD'v:mr	B@*友情链接@!zm@*@!JVb@*J@#@&.+kwGUk+RS.kD+Pr@!sk@*@!mP4DnW{BC/a^tmV m/wv~Dl.oO{Bhmk	B@*服务器情况@!zm@*@!JVr@*r@#@&./wKU/RhMrO+,J@!Vr@*@!C,t.+6xBnECUT*{i2^WCNwr^+ m/aBPDlML+D'v:mkUv@*上传文件管理@!zm@*@!JVk@*E@#@&M+kwGxdnch.kDnPr@!sr@*@!l~4M+W'EV!lUT*|lNsk	 lkwvPDl.LY'EhlbxB@*管理员管理@!&l@*@!JVr@*E@#@&Dn/aGxk+ AMkYn~r@!sk@*@!mP4M+6'B0EmUol{8VKo CkwB,OlMo+Dxv:mk	B@*登陆日志@!&C@*@!&Vb@*J@#@&.nkwWUdRADbOPE@!Vb@*@!mP4.+6'v3!lULl{N(m4mm3!2 lkwQl^YrG	'$l1VEafCOmBPOCMonY{vslr	B@*数据库备份@!zm@*@!&Vb@*E@#@&oLAAAA==^#~@%>
  			</ul>
		</dd>
	</dl><!-- Item 20 End -->
<!-- Item 24 Strat -->

<dl>
    <dt><a href="###" onclick="showHide('items23');" target="_self"><%#@~^FQAAAA==./2Kxk+RSDbO+,J程序版本ELAYAAA==^#~@%></a></dt>
    <dd id="items23" style="display:block;">
	<%#@~^BAEAAA==@#@&DnkwKx/RS.kD+~J@!Es@*r@#@&Mn/aWxkn hMkD+~J@!sb@*@!l,4D0xv4YY2lJzAhS 0EC	olRmK:JvPDl.oYxv|4VmU3E@*|!CUolZs/+R+@!Jl@*@!Jsk@*J@#@&M+/2G	/nRS.bYn,J@!Vk@*@!m~tM+W'EtOOa)zJ84kR3!CUolR1Whzv~Dl.oO'E{8smx3v@*官方论坛@!zC@*@!&^k@*r@#@&D+kwKU/RADbYn~r@!z!s@*r@#@&i77r0gAAA==^#~@%>
		</dd>
	</dl><!-- Item 24 End -->

</div>

</body>
</html>