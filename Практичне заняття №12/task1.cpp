#include <SFML/Graphics.hpp>
#include <cmath>
using namespace std;
using namespace sf;

int modeNow = 1;

void drawAstroid(RenderWindow &w) {
    w.clear(Color::White);
    Vector2u sz = w.getSize();
    float a = 80.f;
    float cx1 = sz.x * 0.25f;
    float cx2 = sz.x * 0.75f;
    float cy  = sz.y * 0.5f;

    VertexArray pix(Points);
    for (int i = 0; i <= 360; i++) {
        float t = 2 * 3.14159f * i / 360.f;
        float x = a * pow(cos(t), 3.f);
        float y = a * pow(sin(t), 3.f);
        pix.append(Vertex(Vector2f(cx1 + x, cy + y), Color::Blue));
    }

    VertexArray line(LineStrip);
    for (int i = 0; i <= 360; i++) {
        float t = 2 * 3.14159f * i / 360.f;
        float x = a * pow(cos(t), 3.f);
        float y = a * pow(sin(t), 3.f);
        line.append(Vertex(Vector2f(cx2 + x, cy + y), Color::Red));
    }

    w.draw(pix);
    w.draw(line);
}

void drawShapes(RenderWindow &w) {
    w.clear(Color(230,230,230));

    CircleShape arc(40);
    arc.setFillColor(Color::Transparent);
    arc.setOutlineColor(Color::Black);
    arc.setOutlineThickness(3);
    arc.setPosition(40,40);

    CircleShape chord(40);
    chord.setFillColor(Color::Yellow);
    chord.setOutlineColor(Color::Black);
    chord.setOutlineThickness(2);
    chord.setPosition(180,40);

    CircleShape ell(25);
    ell.setScale(2.f,1.f);
    ell.setFillColor(Color::Cyan);
    ell.setOutlineColor(Color::Black);
    ell.setOutlineThickness(2);
    ell.setPosition(330,55);

    CircleShape pie(40,40);
    pie.setFillColor(Color::Magenta);
    pie.setOutlineColor(Color::Black);
    pie.setOutlineThickness(2);
    pie.setPosition(480,40);

    ConvexShape poly;
    poly.setPointCount(5);
    poly.setPoint(0, Vector2f(60,200));
    poly.setPoint(1, Vector2f(80,170));
    poly.setPoint(2, Vector2f(100,190));
    poly.setPoint(3, Vector2f(120,170));
    poly.setPoint(4, Vector2f(140,200));
    poly.setFillColor(Color::Green);

    RectangleShape rect(Vector2f(80,40));
    rect.setFillColor(Color::Blue);
    rect.setPosition(220,180);

    RectangleShape round(Vector2f(80,40));
    round.setFillColor(Color(200,100,50));
    round.setPosition(380,180);
    round.setOutlineColor(Color::Black);
    round.setOutlineThickness(6);

    w.draw(arc);
    w.draw(chord);
    w.draw(ell);
    w.draw(pie);
    w.draw(poly);
    w.draw(rect);
    w.draw(round);
}

void drawLineStyles(RenderWindow &w) {
    w.clear(Color::White);
    Vector2u sz = w.getSize();
    float width = (float)sz.x;

    for (int i=0;i<7;i++) {
        float y = 40.f + i*40.f;
        if (i==0) {
            VertexArray l(Lines,2);
            l[0].position = Vector2f(20,y);
            l[1].position = Vector2f(width-20,y);
            l[0].color = l[1].color = Color::Black;
            w.draw(l);
        } else if (i==1) {
            for (float x=20;x<width-20;x+=20) {
                VertexArray l(Lines,2);
                l[0].position = Vector2f(x,y);
                l[1].position = Vector2f(x+10,y);
                l[0].color = l[1].color = Color::Black;
                w.draw(l);
            }
        } else if (i==2) {
            for (float x=20;x<width-20;x+=8) {
                VertexArray l(Lines,2);
                l[0].position = Vector2f(x,y-2);
                l[1].position = Vector2f(x,y+2);
                l[0].color = l[1].color = Color::Black;
                w.draw(l);
            }
        } else if (i==3) {
            RectangleShape r(Vector2f(width-40,3));
            r.setPosition(20,y-1);
            r.setFillColor(Color::Red);
            w.draw(r);
        } else if (i==4) {
            RectangleShape r(Vector2f(width-40,5));
            r.setPosition(20,y-2);
            r.setFillColor(Color::Blue);
            w.draw(r);
        } else if (i==5) {
            for (float x=20;x<width-20;x+=16) {
                RectangleShape r(Vector2f(10,3));
                r.setPosition(x,y-1);
                r.setFillColor(Color::Green);
                w.draw(r);
            }
        } else if (i==6) {
            for (float x=20;x<width-20;x+=4) {
                RectangleShape r(Vector2f(2,8));
                r.setPosition(x,y-4);
                if ((int)x%16<8) r.setFillColor(Color::Black);
                else r.setFillColor(Color::White);
                w.draw(r);
            }
        }
    }
}

void drawSinusoids(RenderWindow &w) {
    w.clear(Color::White);
    Vector2u sz = w.getSize();
    int midY = sz.y/2;
    int midX = sz.x/2;
    int wHalf = midX;

    VertexArray pix(Points);
    for (int px=0;px<wHalf;px++) {
        float x = px * 4.f * 3.14159f / wHalf;
        float y = sin(x);
        int py = midY - (int)(y * (sz.y/3));
        pix.append(Vertex(Vector2f((float)px, (float)py), Color::Black));
    }

    VertexArray line(LineStrip);
    for (int px=0;px<wHalf;px++) {
        float x = px * 4.f * 3.14159f / wHalf;
        float y = sin(x);
        int py = midY - (int)(y * (sz.y/3));
        line.append(Vertex(Vector2f((float)(midX+px), (float)py), Color::Black));
    }

    w.draw(pix);
    w.draw(line);
}

int main() {
    RenderWindow window(VideoMode(800,600),"Lab Graphics");
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed) window.close();
            if (e.type == Event::KeyPressed) {
                if (e.key.code == Keyboard::Num1) modeNow = 1;
                if (e.key.code == Keyboard::Num2) modeNow = 2;
                if (e.key.code == Keyboard::Num3) modeNow = 3;
                if (e.key.code == Keyboard::Num4) modeNow = 4;
                if (e.key.code == Keyboard::Escape) window.close();
            }
        }

        if (modeNow == 1)      drawAstroid(window);
        else if (modeNow == 2) drawShapes(window);
        else if (modeNow == 3) drawLineStyles(window);
        else if (modeNow == 4) drawSinusoids(window);

        window.display();
    }

    return 0;
}
