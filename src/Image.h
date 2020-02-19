#pragma once
#ifndef __IMAGE__
#define __IMAGE__
#include "DisplayObject.h"
class Image : public DisplayObject {
public:
	Image(std::string imagePath, std::string n);
	~Image();

	void draw() override;
	void clean() override;
	void update() override;
private:
	std::string name;
};
#endif // !Image
