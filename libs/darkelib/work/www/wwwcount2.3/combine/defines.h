#ifndef DEFINES_H
#define DEFINES_H
/*
** some important clinet_data
*/

/*
** from ImageMagick
*/

#define DownShift(x) ((int) ((x)+(1L << 15)) >> 16)

#ifndef False
#define False  0
#endif

#define Max(x,y)  (((x) > (y)) ? (x) : (y))
#define Min(x,y)  (((x) < (y)) ? (x) : (y))
#define MinInfoSize (1 << 18)

#ifndef True
#define True  1
#endif

#define UpShift(x) ((x) << 16)
#define UpShifted(x) ((int) ((x)*(1L << 16)+0.5))
#define AbsoluteValue(x)  ((x) < 0 ? -(x) : (x))
#define DegreesToRadians(x) ((x)*3.14159265358979323846/180.0)
#define RadiansToDegrees(x) ((x)*180/3.14159265358979323846)

#define Intensity(color)  (unsigned int)  \
  ((unsigned int) ((color).red*77+(color).green*150+(color).blue*29) >> 8)

#define ColorShift(color)  (((unsigned int) (color)) >> 8)

#define XStandardPixel(map,color,dx)  (unsigned long) (map->base_pixel+  \
  ((color.red*map->red_max+(1 << (dx-1)))/((1 << dx)-1))*map->red_mult+  \
  ((color.green*map->green_max+(1 << (dx-1)))/((1 << dx)-1))*map->green_mult+ \
  ((color.blue*map->blue_max+(1 << (dx-1)))/((1 << dx)-1))*map->blue_mult)

#define MaxColormapSize		65535
#define MaxImageSize		(4096*4096)
#define MaxRGB				255
#define MaxRunlength		255
#define MaxTextLength		2048

#define Transparent         0
#define Opaque              255

#define UndefinedId			0

#define UndefinedClass		0
#define DirectClass			1
#define PseudoClass			2

#define UndefinedColorspace	0
#define RGBColorspace		1
#define GRAYColorspace		2
#define XYZColorspace		3
#define YCbCrColorspace		4
#define YIQColorspace		5
#define YUVColorspace		6
#define OHTAColorspace		7

#define UndefinedCompression			0
#define NoCompression					1
#define RunlengthEncodedCompression		2
#define QEncodedCompression				3
#define LZWCompression					4
#define PACKBITSCompression				5

#define UndefinedInterlace				0
#define NoneInterlace					1
#define LineInterlace					2
#define PlaneInterlace					3

#define UndefinedCompositeOp			0
#define OverCompositeOp					1
#define InCompositeOp					2
#define OutCompositeOp					3
#define AtopCompositeOp					4
#define XorCompositeOp					5
#define PlusCompositeOp					6
#define MinusCompositeOp				7
#define AddCompositeOp					8
#define SubtractCompositeOp				9
#define DifferenceCompositeOp			10
#define ReplaceCompositeOp				11
#define BlackTransparentOp              12

#define HighlightModulate   125
#define ShadowModulate      135

#endif /*DEFINES_H*/
