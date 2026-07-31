function ADInfoList()
{
	this.ADCode=new Array();
	this.ADUrl=new Array();
	this.ADMode=new Array();
	this.ADType=new Array();
	this.ADText=new Array();
	this.ADWidth=new Array();
	this.ADHeight=new Array();
}

//加入收藏
function AddFav()
{
	window.external.addFavorite(window.document.location.href,document.title);
}

function Trim(strValue)
{
	return strValue.replace(/^\s*|\s*$/g,"");
}

function SetCookie(sName, sValue)
{
  document.cookie = sName + "=" + escape(sValue);
}

function GetCookie(sName)
{
  var aCookie = document.cookie.split(";");
  for (var i=0; i < aCookie.length; i++)
  {
    var aCrumb = aCookie[i].split("=");
    if (sName == Trim(aCrumb[0])) 
    {
    	return unescape(aCrumb[1]);
    }
  }

  return null;
}

function Request(strName)
{
	var strHref = window.document.location.href;
	var intPos = strHref.indexOf("?");
	var strRight = strHref.substr(intPos + 1);

	var arrTmp = strRight.split("&");
	for(var i = 0; i < arrTmp.length; i++)
	{
		var arrTemp = arrTmp[i].split("=");

		if(arrTemp[0].toUpperCase() == strName.toUpperCase()) return arrTemp[1];
	}
	return "";
}

//选择反选
function SelectAll(form)
{
	for (var i=0; i < form.elements.length; i++)
	{
		if (form.elements[i].type == "checkbox" || form.elements[i].type == "radio")
		{
			form.elements[i].checked = !form.elements[i].checked;
		}
	}
}

//图片滚轮缩放
function bbimg(obj)
{
	//return false;	//如果不需要滚轮缩放,请删除本行前面的//
	var zoom=parseInt(obj.style.zoom, 10)||100;zoom+=event.wheelDelta/12;if (zoom>0) obj.style.zoom=zoom+'%';
	return false;
}

//正文点击图片打开新窗口
function openImgSrc(obj)
{
	//return;	//如果不需要打开新窗口,请删除本行前面的//
	if (obj.resized==1 && obj.parentElement.tagName!="A")
	{
		window.open(obj.src);
	}
}

//正文图片载入大小限制
function changeImgSize(obj)
{
	var maxImageWidth = 500;	//图片的最大宽度
	obj.style.cursor="hand";
	obj.resized=1;

	if(obj.width > maxImageWidth)
	{		
		obj.style.width = maxImageWidth;
	}
}

function getByID(StringID)
{
	try
	{
		return document.getElementById(StringID);
	}
	catch (e){}	
}

//前台缩略图按比例缩放函数
//传入参数分别为,图片路径,显示宽度,显示高度,自动按比例设置大小,图片替换文字,图片的Style,图片的CSS类
function ShowPreviewImg(imageSrc,dispWidth,dispHeight,useAutoSize,Tips,Style,CssClass)
{
	//By Xfok.Com
	var newWidth = dispWidth;
	var newHeight = dispHeight;
	var sourceWidth;	//源图片的宽度
	var sourceHeight;	//源图片的高度
	useAutoSize = eval(useAutoSize.toLowerCase());
	var outString = '<IMG Src="{Src}" Width="{Width}" Height="{Height}" Border="0"';
	//使用自动按比例缩放
	if (useAutoSize)
	{
		imageOriginal = new Image() ;
		imageOriginal.src = imageSrc ;
		sourceWidth = imageOriginal.width;
		sourceHeight = imageOriginal.height;
		newHeight = ((newWidth / 4) * 3);
		if (sourceWidth == 0)
		{
			sourceWidth = newWidth;
			sourceHeight = newHeight;
		}
		if (( Math.round(sourceWidth) / Math.round(sourceHeight)) >= 1.3333333333333333)
		{
			newHeight = ((sourceHeight * newWidth) / sourceWidth); 
		}
		else
		{
			newWidth = ((sourceWidth * newHeight) / sourceHeight); 
		}
	}
	outString = outString.replace("{Src}",imageSrc);
	outString = outString.replace("{Width}",newWidth);
	outString = outString.replace("{Height}",newHeight);
	if (Tips != null)
	{
		outString += " Alt=" + Tips;
	}
	if (Style != null)
	{
		outString += " Style=" + Style;
	}
	if (Style != null)
	{
		outString += " Class=" + CssClass;
	}
	outString += ">";
	document.write(outString);
}

//导航动态显示部分
//By Xfok.Com
function ShowNavMenu(ID,NavMenuCount)
{
	for ( var i = 0; i < NavMenuCount; i++ )
	{
		try
		{
			document.all['NavMenu_' + i].style.display = "none";
			if ( i == ID)
			{
				document.all['NavMenu_' + ID].style.display = "inline";
			}
		}
		catch(e){}
	}
}

//彩秀发到手机调用函数(发送缩略图)
//PreviewImg:要发送图片的http地址
//Color:字体颜色
function SendToCaiShow(PreviewImg,Color)
{
	var CaiShow_Uid = 3462;	//你的彩秀会员ID
	var HostName = document.location.protocol + "..//" + document.location.host;	//获取当前网址
	PreviewImg = PreviewImg.toLowerCase();
	if (Color == null || Color == "")
	{
		Color = "#000000";
	}
	if (PreviewImg.substring(0,7) != "http://")
	{
		PreviewImg = HostName + PreviewImg;
	}
	document.write ("<a href='javascript:' onClick=\"javascript:window.open('../www.caishow.com/cooperation/pic.asp@f=" + CaiShow_Uid + "&picUrl=" + PreviewImg + "','caishow','width=382,height=287');return false;\" style='color=" + Color + "'>发到手机</a>");
}

//广告区函数群
//--------------------------------
//广告相关定义如下
//ADList_0.ADCode[k] = 此为广告代码
//ADList_0.ADUrl[k]  = 广告连接
//ADList_0.ADMode[k] = 广告模式(图片=1,FLASH=2,HTML=3)
//ADList_0.ADType[k] = 广告类型
//ADList_0.ADText[k] = 广告说明
//ADList_0.ADWidth[k] = 广告宽度
//ADList_0.ADHeight[k] = 广告高度
//广告输出函数
function ShowAD(ADList)
{
	var thisads = ADList.ADType.length;
	var now = new Date()
	var sec = now.getSeconds()
	var k = sec % thisads;
	switch(ADList.ADMode[k]){
		case "1":	//图片广告
			document.write('<div align="center">');
			document.write('<a href=\"' + ADList.ADUrl[k] + '\" target=\"_blank\">');
			document.write('<img src=\"' + ADList.ADCode[k] + '\" width=')
			document.write(ADList.ADWidth[k] + ' height=' + ADList.ADHeight[k] + ' ');
			document.write('alt=\"' + ADList.ADText[k] + '\" border=0 valign=\"absmiddle\"></a>');
			document.write('</div>');
			break;
		case "2":	//FLASH广告
			document.write('<OBJECT codeBase=http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=4,0,2,0 classid=clsid:D27CDB6E-AE6D-11cf-96B8-444553540000 width=\"'+ADList.ADWidth[k]+'"\" height=\"'+ADList.ADHeight[k]+'\"><PARAM NAME=movie VALUE=\"'+ADList.ADCode[k]+'\"><PARAM NAME=quality VALUE=high><embed src=\"'+ADList.ADCode[k]+'\" quality=high pluginspage=\"../www.macromedia.com/shockwave/download/index.cgi@P1_Prod_Version=ShockwaveFlash\" type=\"application/x-shockwave-flash\" width=\"'+ADList.ADWidth[k]+'\" height=\"'+ADList.ADHeight[k]+'\">'+ADList.ADCode[k]+'</embed></OBJECT>');
			break;
		case "3":	//HTML广告
			document.write(ADList.ADCode[k]);
			break;
		case "4":	//漂浮广告
			document.write('<a href="' + ADList.ADUrl[k] + '" target="_blank" onmouseover=stopme("MoveAD"); onmouseout=movechip("MoveAD");>');
			document.write('<img src="' + ADList.ADCode[k] + '" border="0" width="'+ ADList.ADWidth[k] + '" height="' + ADList.ADHeight[k] + '" alt=' + ADList.ADText[k] + '></a>');
			break;
	}
}

//检查登陆表单
function CheckLogin(form){
	if (form.UserName.value==""){
		alert("请输入用户名");
		form.UserName.focus();
		return false;
	}
	if (form.PassWord.value==""){
		alert("请输入用户密码");
		form.PassWord.focus();
		return false;
	}
}

function openWindow(url, width, height){
	var Win = window.open(url,"openWin",'width=' + width + ',height=' + height + ',resizable=0,scrollbars=yes,menubar=no,status=yes' );
}

//漂浮广告部分
var brOK=false;
var mie=false;
var vmin=2;
var vmax=5;
var vr=3;
var timer1;
var MoveAD;

function movechip(chipname){
	if(brOK){
		eval("chip="+chipname);
		if(!mie){
			pageX=window.pageXOffset;
			pageW=window.innerWidth;
			pageY=window.pageYOffset;
			pageH=window.innerHeight;
		}else{
			pageX=window.document.body.scrollLeft;
			pageW=window.document.body.offsetWidth-8;
			pageY=window.document.body.scrollTop;
			pageH=window.document.body.offsetHeight;
		}
		chip.xx=chip.xx+chip.vx;
		chip.yy=chip.yy+chip.vy;
		chip.vx+=vr*(Math.random()-0.5);
		chip.vy+=vr*(Math.random()-0.5);
		if(chip.vx>(vmax+vmin))  chip.vx=(vmax+vmin)*2-chip.vx;
		if(chip.vx<(-vmax-vmin)) chip.vx=(-vmax-vmin)*2-chip.vx;
		if(chip.vy>(vmax+vmin))  chip.vy=(vmax+vmin)*2-chip.vy;
		if(chip.vy<(-vmax-vmin)) chip.vy=(-vmax-vmin)*2-chip.vy;
		if(chip.xx<=pageX){
			chip.xx=pageX;
			chip.vx=vmin+vmax*Math.random();
		}
		if(chip.xx>=pageX+pageW-chip.w){
			chip.xx=pageX+pageW-chip.w;
			chip.vx=-vmin-vmax*Math.random();
		}
		if(chip.xx>=680){
			chip.xx=chip.xx-20;
			chip.vx=-vmin-vmax*Math.random();
		}
		if(chip.yy<=pageY){
			chip.yy=pageY;
			chip.vy=vmin+vmax*Math.random();
		}
		if(chip.yy>=pageY+pageH-chip.h){
			chip.yy=pageY+pageH-chip.h;
			chip.vy=-vmin-vmax*Math.random();
		}
		if(!mie){
			eval('document.'+chip.named+'.top ='+chip.yy);
			eval('document.'+chip.named+'.left='+chip.xx);
		}else{
			eval('document.all.'+chip.named+'.style.pixelLeft='+chip.xx);
			eval('document.all.'+chip.named+'.style.pixelTop ='+chip.yy);
		}
		chip.timer1=setTimeout("movechip('"+chip.named+"')",80);
	}
}

function stopme(chipname){
	if(brOK){
		eval("chip="+chipname);
		if(chip.timer1!=null){
			clearTimeout(chip.timer1)
		}
	}
}

function MoveAD(){
	if(navigator.appName.indexOf("Internet Explorer")!=-1){
		if(parseInt(navigator.appVersion.substring(0,1))>=4) brOK=navigator.javaEnabled();mie=true;
	}
	if(navigator.appName.indexOf("Netscape")!=-1){
		if(parseInt(navigator.appVersion.substring(0,1))>=4) brOK=navigator.javaEnabled();
	}
	MoveAD.named="MoveAD";
	MoveAD.vx=vmin+vmax*Math.random();
	MoveAD.vy=vmin+vmax*Math.random();
	MoveAD.w=1;
	MoveAD.h=1;
	MoveAD.xx=0;
	MoveAD.yy=0;
	MoveAD.timer1=null;
	movechip("MoveAD");
}

function MM_swapImgRestore() { //v3.0
  var i,x,a=document.MM_sr; for(i=0;a&&i<a.length&&(x=a[i])&&x.oSrc;i++) x.src=x.oSrc;
}

function MM_preloadImages() { //v3.0
  var d=document; if(d.images){ if(!d.MM_p) d.MM_p=new Array();
    var i,j=d.MM_p.length,a=MM_preloadImages.arguments; for(i=0; i<a.length; i++)
    if (a[i].indexOf("#")!=0){ d.MM_p[j]=new Image; d.MM_p[j++].src=a[i];}}
}

function MM_findObj(n, d) { //v4.01
  var p,i,x;  if(!d) d=document; if((p=n.indexOf("?"))>0&&parent.frames.length) {
    d=parent.frames[n.substring(p+1)].document; n=n.substring(0,p);}
  if(!(x=d[n])&&d.all) x=d.all[n]; for (i=0;!x&&i<d.forms.length;i++) x=d.forms[i][n];
  for(i=0;!x&&d.layers&&i<d.layers.length;i++) x=MM_findObj(n,d.layers[i].document);
  if(!x && d.getElementById) x=d.getElementById(n); return x;
}

function MM_swapImage() { //v3.0
  var i,j=0,x,a=MM_swapImage.arguments; document.MM_sr=new Array; for(i=0;i<(a.length-2);i+=3)
   if ((x=MM_findObj(a[i]))!=null){document.MM_sr[j++]=x; if(!x.oSrc) x.oSrc=x.src; x.src=a[i+2];}
}