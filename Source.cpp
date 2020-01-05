#include "Simple_window.h"
#include "Graph.h"
int main()
{
	using namespace Graph_lib; // Графические средства
	Point t1{ 100 , 100 }; // Задаем левый верхний угол окна
	Simple_window win{ t1 , 600 , 400, "My window" }; // Простое окно
	Axis xa{ Axis::x, Point(20 , 300) , 280, 10, "x axis" };
	Axis ya{ Axis::y, Point{20 , 300} ,280, 10, "y axis" };
	Function sine{ sin , 0 , 100 , Point{20 , 150} , 1000 , 50 , 50 };
	Polygon_BS poly;

	poly.add(Point{ 300,200 });
	poly.add(Point{ 350 ,100 });
	poly.add(Point{ 400,200 });
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	//poly.set_color(Color::red); // Уточняем свойства poly
	win.attach(poly);
	win.attach(xa);
	win.wait_for_button();

	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);
	win.wait_for_button();

	sine.set_color(Color::blue);
	win.attach(sine);
	win.wait_for_button();

	Rectangle_BS r{ Point{200 ,200 } , 100 , 50 };
	win.attach(r);
	win.wait_for_button();

	Closed_polyline poly_rect;
	poly_rect.add(Point{ 100,50 });
	poly_rect.add(Point{ 200,50 });
	poly_rect.add(Point{ 200,100 });
	poly_rect.add(Point{ 100,100 });
	poly_rect.add(Point(50, 75));	

	r.set_fill_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dash, 4));
	poly_rect.set_style(Line_style(Line_style::dash, 2));
	poly_rect.set_fill_color(Color::green);

	win.attach(poly_rect);
	win.wait_for_button();

	Image ii{ Point{100, 50} , "Jdun.jpg" };
	win.attach(ii); // в формате jpg
	win.set_label("Canvas 4");
	win.wait_for_button();

	Circle c{ Point{100,200} , 50 };
	Ellipse_BS e{ Point{100,200}, 75 , 25 };
	e.set_color(Color::dark_red);
	Mark m{ Point{100,200 }, 'x' };
	ostringstream oss;
	oss << "screen size : " << x_max() << "*" << y_max() << "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes{Point{100, 20}, oss.str() };
	Image cal{Point{255,255}, "cute.gif" }; // 320 *240 пикселей, формат gif
	cal.move(130, -200);
	cal.set_mask(Point{40, 40}, 200, 150);
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.attach(cal);
	win.set_label("Canvas #12");
	win.wait_for_button();
};