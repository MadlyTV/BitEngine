//#include "src\graphics\window.h"
//#include "src\graphics\shader.h"
//
//#include "src\utils\timer.h"
//
//#include "src\graphics\2D\batchrenderer2D.h"
//#include "src\graphics\2D\sprite.h"
//
//#include "Exampel\tilelayer.h"
//
//#include "src\graphics\layers\group.h"
//
//#include "src\utils\FileUtils.h"
//
//#include "src\maths\maths.h"
//
//#include <FreeImage.h>
//
//#include <time.h>
//#include "src\graphics\2D\texture.h"
//
//#define test3d 0
//#define BATCH_RENDERER_TEST 1

//My Little Play World
#if 0
int main() {

//	using namespace BitEngine;
//	using namespace graphics;
//	using namespace maths;
//
//	Window window("PAOWS",1280,720);
//	glClearColor(0.8f, 0.06f, 0.46f, 1); //Pink background
//
//
//#if test3d
//	mat4 persp = mat4::perspective(90, 1, 0.0f, 1000.0f);
//#else
//#endif
//	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
//
//	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
//	shader.enable();
//	shader.setUniformMat4("pr_matrix", ortho);
//
//	//Cube3D cube(maths::vec3(-0.5, -0.5, -1), maths::vec3(1, 1, 1), maths::vec4(0.6071, 0.3929, 0, 1), "src/res/imgs/wall.jpg", shader);
//	//Simple3DRenderer renderer;
//	Simple2DRenderer renderer;
//
//#if test3d
//#if 1
//	std::vector<maths::vec3> vert;
//	std::vector<maths::vec2> uvs;
//	std::vector<maths::vec3> norms;
//
//	bool res = FileUtils::loadOBJ("src/res/models/nanosuit/nanosuit.obj", vert, uvs, norms);
//
//	unsigned int vertarray;
//	unsigned int buffer;
//
//	glGenBuffers(1, &buffer);
//	glBindBuffer(GL_ARRAY_BUFFER, buffer);
//	glBufferData(GL_ARRAY_BUFFER, vert.size() * sizeof(maths::vec3), &vert[0], GL_STATIC_DRAW);
//	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
//	glEnableVertexAttribArray(0);
//
//	shader.setUniformMat4("ml_matrix",mat4::translate(maths::vec3(0,-8,-10)));
//#else
//	Model myModel("src/res/models/nanosuit/nanosuit.obj", maths::vec3(0,0,0));
//	shader.setUniformMat4("ml_matrix", mat4::translate(maths::vec3(0, -5, -10)));
//#endif
//#else
//	Renderable2D sprite(maths::vec3(0,1,0), maths::vec2(1,1), maths::vec4(1,1,1,1), shader);
//#endif
//
//	Timer time;
//	float timer = 0;
//	unsigned int frames = 0;
//
//	while (!window.closed())
//	{	
//		window.clear();
//		//Code goes under me
//#if test3d
//		glDrawArrays(GL_TRIANGLES,0,vert.size());
//		
//		shader.setUniformMat4("ml_matrix", mat4::translate(maths::vec3(0, 0, 0)));
//		shader.setUniformMat4("vw_matrix", mat4::rotate(20*time.elapsed(),maths::vec3(0,1,0)));
//		shader.setUniformMat4("ml_matrix", mat4::translate(maths::vec3(0, -5, -10)));
//		
//		//myModel.Draw(shader);
//
//		//renderer.submit(&cube);
//		//renderer.flush();
//#else
//		renderer.submit(&sprite);
//		renderer.flush();
//#endif
//		//Code goes over me
//		window.update();
//		frames++;
//		if (time.elapsed() - timer > 1.0f) {
//			timer += 1.0f;
//			printf("%d FPS\n", frames);
//			frames = 0;
//		}
//	}

	using namespace BitEngine;
	using namespace graphics;
	using namespace maths;

	//Creates a window and assigns a color to it
	Window window("BitEngine 2D test world",1280,720);
	glClearColor(0,1,0,1);

	//Creates a orthographic view
	//mat4 ortho = mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f);

	//creats a shader
	Shader* shader = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");

	Texture* textures[] =
	{
		new Texture("src/res/imgs/test.png"),
		new Texture("src/res/imgs/test2.png"),
		new Texture("src/res/imgs/test3.png")
	};

	TileLayer layer(shader);

	for (int x = -16.0f; x < 16.0f; x += 1) {
		for (int y = -9.0f; y < 9.0f; y += 1) {
			/*if (rand() % 4 == 0)
				layer.add(new Sprite(x, y, 0.9f, 0.9f, maths::vec4(1, 1, 1, 1)));
			else*/
				layer.add(new Sprite(x, y, 0.9f, 0.9f, textures[rand()%3]));
		}
	}

	//Timers and stuff for the fps counter
	Timer time;
	float timer = 0;
	unsigned int frames = 0;

	while (!window.closed()) {
		window.clear();

		double x, y;
		window.getMousePosition(x, y);
		shader->enable();
		shader->setUniform2f("light_pos", maths::vec2((float)(x * 32.0f / 1280.0f - 16.0f), (float)(9.0f - y * 18.0f / 720.0f)));

		layer.render();

		window.update();

#pragma region Baisc_FPS_Counter
		frames++;
		if (time.elapsed() - timer > 1.0f) {
			timer += 1.0f;
			printf("%d FPS\n", frames);
			frames = 0;
		}
#pragma endregion

	}

	for (int i = 0; i < 3; i++) {
		delete textures[i];
	}

	return 0;
}
#endif

//test för freeimage
#if 0 
int main() 
{
	const char* filename = "src/res/imgs/test.png";

	//image format
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	//pointer to the image, once loaded
	FIBITMAP *dib(0);
	//pointer to the image data
	BYTE* bits(0);
	//image width and height
	unsigned int width(0), height(0);
	//OpenGL's image ID to map to
	GLuint gl_texID;

	//check the file signature and deduce its format
	fif = FreeImage_GetFileType(filename, 0);
	//if still unknown, try to guess the file format from the file extension
	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(filename);
	//if still unkown, return failure
	if (fif == FIF_UNKNOWN)
		return false;

	//check that the plugin has reading capabilities and load the file
	if (FreeImage_FIFSupportsReading(fif))
		dib = FreeImage_Load(fif, filename);
	//if the image failed to load, return failure
	if (!dib)
		return false;

	//retrieve the image data
	bits = FreeImage_GetBits(dib);
	unsigned int BitsPerPixel = FreeImage_GetBPP(dib);
	//get the image width and height
	width = FreeImage_GetWidth(dib);
	height = FreeImage_GetHeight(dib);
	//if this somehow one of these failed (they shouldn't), return failure
	if ((bits == 0) || (width == 0) || (height == 0))
		return false;

	for (int i = width * height * 3; i > 0; i-=3) {
		std::cout << +bits[i] << ", " << +bits[i+1] << ", " << +bits[i+2] << std::endl;
	}

	return 0;
}
#endif

//test för freetype
#if 0
// This file demonstrates how to render a coloured glyph with a differently
// coloured outline.
//
// Written Feb. 2009 by Erik Möller,
// with slight modifications by Werner Lemberg
//
// Public domain.
//
// Eric uses similar code in real applications; see
//
//   http://www.timetrap.se
//   http://www.emberwind.se
//
// for more.

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_STROKER_H

#include <vector>
#include <fstream>
#include <iostream>

#ifdef _MSC_VER
#define MIN __min
#define MAX __max
#else
#define MIN std::min
#define MAX std::max
#endif

using namespace BitEngine;
using namespace maths;
using namespace graphics;

// Define some fixed size types.

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;


// Try to figure out what endian this machine is using. Note that the test
// below might fail for cross compilation; additionally, multi-byte
// characters are implementation-defined in C preprocessors.

#if (('1234' >> 24) == '1')
#elif (('4321' >> 24) == '1')
#define BIG_ENDIAN
#else
#error "Couldn't determine the endianness!"
#endif


// A simple 32-bit pixel.

union Pixel32
{
	Pixel32()
		: integer(0) { }
	Pixel32(uint8 bi, uint8 gi, uint8 ri, uint8 ai = 255)
	{
		b = bi;
		g = gi;
		r = ri;
		a = ai;
	}

	uint32 integer;

	struct
	{
#ifdef BIG_ENDIAN
		uint8 a, r, g, b;
#else // BIG_ENDIAN
		uint8 b, g, r, a;
#endif // BIG_ENDIAN
	};
};

struct Rect
{
	Rect() { }
	Rect(float left, float top, float right, float bottom)
		: xmin(left), xmax(right), ymin(top), ymax(bottom) { }

	void Include(const vec2 &r)
	{
		xmin = MIN(xmin, r.x);
		ymin = MIN(ymin, r.y);
		xmax = MAX(xmax, r.x);
		ymax = MAX(ymax, r.y);
	}

	float Width() const { return xmax - xmin + 1; }
	float Height() const { return ymax - ymin + 1; }

	float xmin, xmax, ymin, ymax;
};


// TGA Header struct to make it simple to dump a TGA to disc.

#if defined(_MSC_VER) || defined(__GNUC__)
#pragma pack(push, 1)
#pragma pack(1)               // Dont pad the following struct.
#endif

struct TGAHeader
{
	uint8   idLength,           // Length of optional identification sequence.
		paletteType,        // Is a palette present? (1=yes)
		imageType;          // Image data type (0=none, 1=indexed, 2=rgb,
							// 3=grey, +8=rle packed).
	uint16  firstPaletteEntry,  // First palette index, if present.
		numPaletteEntries;  // Number of palette entries, if present.
	uint8   paletteBits;        // Number of bits per palette entry.
	uint16  x,                  // Horiz. pixel coord. of lower left of image.
		y,                  // Vert. pixel coord. of lower left of image.
		width,              // Image width in pixels.
		height;             // Image height in pixels.
	uint8   depth,              // Image color depth (bits per pixel).
		descriptor;         // Image attribute flags.
};

#if defined(_MSC_VER) || defined(__GNUC__)
#pragma pack(pop)
#endif


bool
WriteTGA(const std::string &filename,
	const Pixel32 *pxl,
	uint16 width,
	uint16 height)
{
	std::ofstream file(filename.c_str(), std::ios::binary);
	if (file)
	{
		TGAHeader header;
		memset(&header, 0, sizeof(TGAHeader));
		header.imageType = 2;
		header.width = width;
		header.height = height;
		header.depth = 32;
		header.descriptor = 0x20;

		file.write((const char *)&header, sizeof(TGAHeader));
		file.write((const char *)pxl, sizeof(Pixel32) * width * height);

		return true;
	}
	return false;
}


// A horizontal pixel span generated by the FreeType renderer.

struct Span
{
	Span() { }
	Span(int _x, int _y, int _width, int _coverage)
		: x(_x), y(_y), width(_width), coverage(_coverage) { }

	int x, y, width, coverage;
};

typedef std::vector<Span> Spans;


// Each time the renderer calls us back we just push another span entry on
// our list.

void
RasterCallback(const int y,
	const int count,
	const FT_Span * const spans,
	void * const user)
{
	Spans *sptr = (Spans *)user;
	for (int i = 0; i < count; ++i)
		sptr->push_back(Span(spans[i].x, y, spans[i].len, spans[i].coverage));
}


// Set up the raster parameters and render the outline.

void
RenderSpans(FT_Library &library,
	FT_Outline * const outline,
	Spans *spans)
{
	FT_Raster_Params params;
	memset(&params, 0, sizeof(params));
	params.flags = FT_RASTER_FLAG_AA | FT_RASTER_FLAG_DIRECT;
	params.gray_spans = RasterCallback;
	params.user = spans;

	FT_Outline_Render(library, outline, &params);
}


// Render the specified character as a colored glyph with a colored outline
// and dump it to a TGA.

void
WriteGlyphAsTGA(FT_Library &library,
	const std::string &fileName,
	wchar_t ch,
	FT_Face &face,
	int size,
	const Pixel32 &fontCol,
	const Pixel32 outlineCol,
	float outlineWidth)
{
	// Set the size to use.
	if (FT_Set_Char_Size(face, size << 6, size << 6, 90, 90) == 0)
	{
		// Load the glyph we are looking for.
		FT_UInt gindex = FT_Get_Char_Index(face, ch);
		if (FT_Load_Glyph(face, gindex, FT_LOAD_NO_BITMAP) == 0)
		{
			// Need an outline for this to work.
			if (face->glyph->format == FT_GLYPH_FORMAT_OUTLINE)
			{
				// Render the basic glyph to a span list.
				Spans spans;
				RenderSpans(library, &face->glyph->outline, &spans);

				// Next we need the spans for the outline.
				Spans outlineSpans;

				// Set up a stroker.
				FT_Stroker stroker;
				FT_Stroker_New(library, &stroker);
				FT_Stroker_Set(stroker,
					(int)(outlineWidth * 64),
					FT_STROKER_LINECAP_ROUND,
					FT_STROKER_LINEJOIN_ROUND,
					0);

				FT_Glyph glyph;
				if (FT_Get_Glyph(face->glyph, &glyph) == 0)
				{
					FT_Glyph_StrokeBorder(&glyph, stroker, 0, 1);
					// Again, this needs to be an outline to work.
					if (glyph->format == FT_GLYPH_FORMAT_OUTLINE)
					{
						// Render the outline spans to the span list
						FT_Outline *o =
							&reinterpret_cast<FT_OutlineGlyph>(glyph)->outline;
						RenderSpans(library, o, &outlineSpans);
					}

					// Clean up afterwards.
					FT_Stroker_Done(stroker);
					FT_Done_Glyph(glyph);

					// Now we need to put it all together.
					if (!spans.empty())
					{
						// Figure out what the bounding rect is for both the span lists.
						Rect rect(spans.front().x,
							spans.front().y,
							spans.front().x,
							spans.front().y);
						for (Spans::iterator s = spans.begin();
							s != spans.end(); ++s)
						{
							rect.Include(vec2(s->x, s->y));
							rect.Include(vec2(s->x + s->width - 1, s->y));
						}
						for (Spans::iterator s = outlineSpans.begin();
							s != outlineSpans.end(); ++s)
						{
							rect.Include(vec2(s->x, s->y));
							rect.Include(vec2(s->x + s->width - 1, s->y));
						}

#if 0
						// This is unused in this test but you would need this to draw
						// more than one glyph.
						float bearingX = face->glyph->metrics.horiBearingX >> 6;
						float bearingY = face->glyph->metrics.horiBearingY >> 6;
						float advance = face->glyph->advance.x >> 6;
#endif

						// Get some metrics of our image.
						int imgWidth = rect.Width(),
							imgHeight = rect.Height(),
							imgSize = imgWidth * imgHeight;

						// Allocate data for our image and clear it out to transparent.
						Pixel32 *pxl = new Pixel32[imgSize];
						memset(pxl, 0, sizeof(Pixel32) * imgSize);

						// Loop over the outline spans and just draw them into the
						// image.
						for (Spans::iterator s = outlineSpans.begin();
							s != outlineSpans.end(); ++s)
							for (int w = 0; w < s->width; ++w)
								pxl[(int)((imgHeight - 1 - (s->y - rect.ymin)) * imgWidth
									+ s->x - rect.xmin + w)] =
								Pixel32(outlineCol.r, outlineCol.g, outlineCol.b,
									s->coverage);

						// Then loop over the regular glyph spans and blend them into
						// the image.
						for (Spans::iterator s = spans.begin();
							s != spans.end(); ++s)
							for (int w = 0; w < s->width; ++w)
							{
								Pixel32 &dst =
									pxl[(int)((imgHeight - 1 - (s->y - rect.ymin)) * imgWidth
										+ s->x - rect.xmin + w)];
								Pixel32 src = Pixel32(fontCol.r, fontCol.g, fontCol.b,
									s->coverage);
								dst.r = (int)(dst.r + ((src.r - dst.r) * src.a) / 255.0f);
								dst.g = (int)(dst.g + ((src.g - dst.g) * src.a) / 255.0f);
								dst.b = (int)(dst.b + ((src.b - dst.b) * src.a) / 255.0f);
								dst.a = MIN(255, dst.a + src.a);
							}

						// Dump the image to disk.
						WriteTGA(fileName, pxl, imgWidth, imgHeight);

						delete[] pxl;
					}
				}
			}
		}
	}
}

int main() {
	using namespace BitEngine;
	using namespace graphics;
	using namespace maths;

	Window window("FreeTypeTest",1280,720);
	glClearColor(0, 1, 0, 1);

	// Initialize FreeType.
	FT_Library library;
	FT_Init_FreeType(&library);

	// Open up a font file.
	std::ifstream fontFile("arial.ttf", std::ios::binary);
	if (fontFile)
	{
		// Read the entire file to a memory buffer.
		fontFile.seekg(0, std::ios::end);
		std::fstream::pos_type fontFileSize = fontFile.tellg();
		fontFile.seekg(0);
		unsigned char *fontBuffer = new unsigned char[fontFileSize];
		fontFile.read((char *)fontBuffer, fontFileSize);

		// Create a face from a memory buffer.  Be sure not to delete the memory
		// buffer until you are done using that font as FreeType will reference
		// it directly.
		FT_Face face;
		FT_New_Memory_Face(library, fontBuffer, fontFileSize, 0, &face);

		// Dump out a single glyph to a tga.
		WriteGlyphAsTGA(library,
			"arial.ttf",
			L'B',
			face,
			100,
			Pixel32(255, 90, 30),
			Pixel32(255, 255, 255),
			3.0f);

		// Now that we are done it is safe to delete the memory.
		delete[] fontBuffer;
	}

	// Clean up the library
	FT_Done_FreeType(library);

	Shader* shader = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader->enable();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	TileLayer layer(shader);

	layer.add(new Sprite(-1, -1, 4, 4, maths::vec4(0, 1, 1, 1)));
	layer.add(new Sprite(-2, -2, 4, 4, maths::vec4(1, 0, 1, 1)));

	Timer time;
	float timer = 0;
	unsigned int frames = 0;
	while (!window.closed()) {
		window.clear();

		double x, y;
		window.getMousePosition(x, y);
		shader->enable();
		shader->setUniform2f("light_pos", maths::vec2((float)(x * 32.0f / 1280.0f - 16.0f), (float)(9.0f - y * 18.0f / 720.0f)));

		layer.render();

		window.update();

#pragma region Baisc_FPS_Counter
		frames++;
		if (time.elapsed() - timer > 1.0f) {
			timer += 1.0f;
			printf("%d FPS\n", frames);
			frames = 0;
		}
#pragma endregion

	}
}
#endif

