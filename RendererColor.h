#ifndef RENDERER_COLOR
#define RENDERER_COLOR

class RendererColor
{
public:
	RendererColor(float red = 0.0f, float green = 0.0f, float blue = 0.0f);

	void setRed(float red);
	void setGreen(float green);
	void setBlue(float blue);

	float getRed() const;
	float getGreen() const;
	float getBlue() const;
private:
	float red;
	float blue;
	float green;
};

#endif
