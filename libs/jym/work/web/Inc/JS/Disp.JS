function NextPage()
{
	try
	{
		if (event.keyCode==37) location = getByID("_ctl0_PreLink").href;
		if (event.keyCode==39) location = getByID("_ctl0_NextLink").href;
	}
	catch(e){}
}

//内容字体大小调整
function ChangeSize(size){
	var objSize=getByID('_ctl0_ContentLabel');
	objSize.style.fontSize=size+"px";
}

function Copyright(){
	var TempStr="";
	TempStr+="本站大部分作品来源于互联网，供网友学\n习或者娱乐之用，其版权归原作者所有！\n";
	TempStr+="如果所转载的作品侵犯了您的版权，请来\n信告知，我们会马上处理。\n\n";
	alert(TempStr)
}

//双击滚屏
var currentpos,timer; 
function initializeScroll()
{
	timer=setInterval("scrollwindow()",50);
} 

function scrollclear()
{
	clearInterval(timer);
}

function scrollwindow() 
{
	currentpos=document.body.scrollTop;window.scroll(0,++currentpos);
	if (currentpos != document.body.scrollTop) sc();
} 
document.onmousedown=scrollclear
document.ondblclick=initializeScroll