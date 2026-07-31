/******************************************************************************
  Crossday Discuz! Board - Common Modules for Discuz!
  Modified by: Crossday Studio (http://crossday.com)
  Based upon:  http://www.cnzzz.com
*******************************************************************************/

tPopWait=20;
showPopStep=20;
popOpacity=80;

sPop=null;
curShow=null;
tFadeOut=null;
tFadeIn=null;
tFadeWaiting=null;

document.write("<style type='text/css'id='defaultPopStyle'>");
document.write(".cPopText { font-family: Verdana, Tahoma; background-color: #FFFFCC; border: 1px #000000 solid; font-size: 11px; padding-right: 4px; padding-left: 4px; height: 20px; padding-top: 2px; padding-bottom: 2px; filter: Alpha(Opacity=0)}");

document.write("</style>");
document.write("<div id='popLayer' style='position:absolute;z-index:1000;' class='cPopText'></div>");


function showPopupText(){
	var o=event.srcElement;
	MouseX=event.x;
	MouseY=event.y;
	if(o.alt!=null && o.alt!="") { o.pop=o.alt;o.alt="" }
        if(o.title!=null && o.title!=""){ o.pop=o.title;o.title="" }
        if(o.pop) { o.pop=o.pop.replace("\n","<br>"); o.pop=o.pop.replace("\n","<br>"); }
	if(o.pop!=sPop) {
		sPop=o.pop;
		clearTimeout(curShow);
		clearTimeout(tFadeOut);
		clearTimeout(tFadeIn);
		clearTimeout(tFadeWaiting);	
		if(sPop==null || sPop=="") {
			popLayer.innerHTML="";
			popLayer.style.filter="Alpha()";
			popLayer.filters.Alpha.opacity=0;	
		} else {
			if(o.dyclass!=null) popStyle=o.dyclass 
			else popStyle="cPopText";
			curShow=setTimeout("showIt()",tPopWait);
		}
	}
}

function showIt() {
	popLayer.className=popStyle;
	popLayer.innerHTML=sPop;
	popWidth=popLayer.clientWidth;
	popHeight=popLayer.clientHeight;
	if(MouseX+12+popWidth>document.body.clientWidth) popLeftAdjust=-popWidth-24
		else popLeftAdjust=0;
	if(MouseY+12+popHeight>document.body.clientHeight) popTopAdjust=-popHeight-24
		else popTopAdjust=0;
	popLayer.style.left=MouseX+12+document.body.scrollLeft+popLeftAdjust;
	popLayer.style.top=MouseY+12+document.body.scrollTop+popTopAdjust;
	popLayer.style.filter="Alpha(Opacity=0)";
	fadeOut();
}

function fadeOut(){
	if(popLayer.filters.Alpha.opacity<popOpacity) {
		popLayer.filters.Alpha.opacity+=showPopStep;
		tFadeOut=setTimeout("fadeOut()",1);
	}
}

function ctlent(obj) {
	if((event.ctrlKey && window.event.keyCode == 13) || (event.altKey && window.event.keyCode == 83)) {
		//if(validate(this.document.input)) 
		this.document.input.submit();
	}
}

function checkall(form) {
	for(var i = 0;i < form.elements.length; i++) {
		var e = form.elements[i];
		if (e.name != 'chkall') {
			e.checked = form.chkall.checked;
		}
	}
}

function findobj(n, d) {
	var p,i,x; if(!d) d=document;
	if((p=n.indexOf("?"))>0 && parent.frames.length) {
		d=parent.frames[n.substring(p+1)].document;
		n=n.substring(0,p);
	}
	if(!(x=d[n])&&d.all) {
		x=d.all[n];
	}
	for(i=0;!x && i<d.forms.length;i++) {
		x=d.forms[i][n];
	}
	for(i=0;!x && d.layers&&i>d.layers.length;i++) {
		x=MM_findObj(n,d.layers[i].document);
	}
	return x;
}

function copycode(obj) {
	var rng = document.body.createTextRange();
	rng.moveToElementText(obj);
	rng.scrollIntoView();
	rng.select();
	rng.execCommand("Copy");
	rng.collapse(false);
}

function CheckExistsUserName(){
	var username=document.frmsubmit.username.value;
	var site=document.frmsubmit.sname.value;
	window.open("checkexistuser.php?username="+username+"&site="+site,"Check","width=200,height=20,status=0,scrollbars=0,resizable=1,menubar=0,toolbar=0,location=0");
}

function CheckExistsUserCName(){
	var cname=document.frmsubmit.cname.value;
	var site=document.frmsubmit.sname.value;
	window.open("checkexistuser.php?cname="+cname+"&site="+site,"Check","width=200,height=20,status=0,scrollbars=0,resizable=1,menubar=0,toolbar=0,location=0");
}

document.onmouseover=showPopupText;