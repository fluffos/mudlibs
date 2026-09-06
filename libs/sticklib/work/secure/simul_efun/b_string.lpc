public varargs
string b_string(string strInput, int intWidth, int intIndent)
{
    string	strOutput, *strArray;
    int	intSpace, intChar, intI, intLen, intInd;

    if(!strInput)
	return strInput;

    if(intWidth > 72)
	intWidth = 72;

    intSpace = -1;
    intChar = 0;
    intInd = 0;
    intLen = sizeof(strInput);

    for(intI = 0; intI < intLen; intI++) {
	// Optimized a bit, -+ Doomdark 17-Apr-99 +-
	if (strInput[intI] == ' ')
	    //(strInput[intI..intI] == " ")
	    intSpace = intI;

	if ((intI - intChar) > (intWidth - intInd) && intSpace >= 0) {
	    strInput[intSpace..intSpace] = "\n";
	    intChar = intSpace;
	    intSpace = -1;
	    intInd = intIndent;
	}
    }

    if(!intIndent)
	return strInput;

    strArray = explode(strInput, "\n");

    strOutput = strArray[0];
    strOutput += "\n";

    for(intI = 1; intI < sizeof(strArray); intI++) {
	strOutput += sprintf("%-"+intIndent+"s", " ");
	strOutput += strArray[intI];
	strOutput += "\n";
    }

    return strOutput[0..<2];
}
