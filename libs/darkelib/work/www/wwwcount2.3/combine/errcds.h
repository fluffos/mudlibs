/*
 *	errcodes.h	-	various error codes for miv
 *
 *	RCS:
 *		$Revision: 2.3 $
 *		$Date: 1996/05/03 02:21:34 $
 *
 *	Security:
 *		Unclassified
 *
 *	Description:
 *		text
 *
 *	Dependencies:
 *		file1.h
 *
 *	Comments:
 *		text
 *
 *	Development History:
 *		when	who		why
 *	4/21/94		mm		needs a organized list of error codes
 */

#ifndef ERRCODES_H
#define ERRCODES_H

/*
** X Related
*/

#define	MALLOC_FAILED_STANDARD_COLORMAP	300

#define OPEN_FAILED				99
/*
**	TIFF FILES
*/

#define	UNABLE_TO_OPEN_TIFF		100
#define	MALLOC_FAILED			101
#define	UNABLE_TO_READ_TIFF		102
#define NO_TIFF_LIBRARY			103

#define UNKNOWN_IMAGE_TYPE      104

/*
** GRAY scale and RGB image Error codes
*/

#define	MALLOC_FAILED_IMAGE_PIXELS		200
#define MALLOC_FAILED_IMAGE_COLORMAP	201
#define MALLOC_FAILED_PICTURE			202
#define READ_DATA_FAILED				203

/*
** TGA FILES
*/
#define NOT_A_TARGA_FILE				300
#define EMPTY_IMAGE_STRUCT				301
#define	INVALID_PARAMETERS				308
#define NO_IMAGE_DATA					309
/*
** SUN_RASTER Files
*/
#define NOT_A_SUNRASTER					302
#define UNKNOWN_COLORMAP_TYPE			303

/*
**	XWD FILES
*/
#define	XWD_VERSION_MISMATCH			304
#define XWD_HEADER_TOOSMALL				305
#define XWD_INVALID_HEADER				306
#define	XWD_COLORMAP_READERR			307

/*
** GIF
*/

#define READ_ERROR						314
#define NOT_A_GIF_FILE					315
#define FAILED_TO_READ_SCREEND			316
#define	READ_ERR_EXT_BLOCK				317
#define READ_ERR_WIDTH_HEIGHT			318
#define CORRUPT_GIF_IMAGE				319

/*
** JPEG
*/

#define UNABLE_TO_DISPLAY_JPEG			320
#define JPEG_LIBRARY_NOT_AVAILABLE		322
/*
** XBM
*/
#define INVALID_XBM_FILE				321

/*
** Write
*/
#define	FAILED_TO_OPEN_FILE				400

#endif	/* ERRCODES_H */
