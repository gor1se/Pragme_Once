#pragma once
class Spielstein
{
private:
	int x1, y1, x2, y2;

public:
	Spielstein(int x1_para, int y1_para, int x2_para, int y2_para) {
		this->x1 = x1_para;
		this->y1 = y1_para;
		this->x2 = x2_para;
		this->y2 = y2_para;
	};

	int get_x1() const { return x1; }
	void set_x1(int x1) { this->x1 = x1; }
	int get_y1() const { return y1; }
	void set_y1(int y1) { this->y1 = y1; }
	int get_x2() const { return x2; }
	void set_x2(int x2) { this->x2 = x2; }
	int get_y2() const { return y2; }
	void set_y2(int y2) { this->y2 = y2; }

	void draw_Spielstein(int x1, int y2, int size);

	void setze_Spielstein(int grid[][10], int size1 =10, int size2 = 10);

};

