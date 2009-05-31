#include "CFreeTypeGX.h"
#include "FreeTypeGX.h"

extern "C" {


CFreeTypeGX * CFreeTypeGX_new()
{
	FreeTypeGX *f = new FreeTypeGX();
	
	return (CFreeTypeGX*)f;
}

void CFreeTypeGX_LoadFont(const CFreeTypeGX *ftgx,uint8_t* fontBuffer, FT_Long bufferSize, FT_UInt pointSize, bool cacheAll)
{
	FreeTypeGX *f = (FreeTypeGX*)ftgx;
	
	f->loadFont(fontBuffer, bufferSize, pointSize, cacheAll);
}

void CFreeTypeGX_DrawText(const CFreeTypeGX *ftgx, uint16_t x, uint16_t y, char *text, GXColor color, uint16_t textStyling)
{
	FreeTypeGX *f = (FreeTypeGX*)ftgx;
	
	wchar_t *strWChar;
	strWChar = new wchar_t[strlen(text) + 1];
	
	int ln = mbstowcs(strWChar, text, strlen(text));
	if(ln < 0) ln = 0;
	strWChar[ln] = (wchar_t)'\0';

	f->drawText(x,y,strWChar,color,textStyling);

	delete strWChar;
}
	
void CFreeTypeGX_DrawTextWithShadow(const CFreeTypeGX *ftgx, uint16_t x, uint16_t y, char *text, GXColor color, GXColor shadowColor, uint16_t textStyling)
{
	FreeTypeGX *f = (FreeTypeGX*)ftgx;

	wchar_t *strWChar;
	strWChar = new wchar_t[strlen(text) + 1];
	
	int ln = mbstowcs(strWChar, text, strlen(text));
	if(ln < 0) ln = 0;
	strWChar[ln] = (wchar_t)'\0';
	
	f->drawTextWithShadow(x, y, strWChar, color, shadowColor, textStyling);

	delete strWChar;
}

wchar_t* CFreeTypeGX_charToWideChar(const CFreeTypeGX *ftgx, char* p)
{
	FreeTypeGX *f = (FreeTypeGX*)ftgx;
	
	return f->charToWideChar(p);
}

uint16_t CFreeTypeGX_getWidth(const CFreeTypeGX *ftgx, wchar_t *text)
{
	FreeTypeGX *f = (FreeTypeGX*)ftgx;
	return f->getWidth(text);
}

uint16_t CFreeTypeGX_getHeight(const CFreeTypeGX *ftgx, wchar_t *text)
{
	FreeTypeGX *f = (FreeTypeGX*)ftgx;
	return f->getHeight(text);
}

#ifdef __cplusplus
}
#endif