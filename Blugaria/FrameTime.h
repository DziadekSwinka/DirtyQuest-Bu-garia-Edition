#ifndef FRAMETIME_H_INCLUDED
#define FRAMETIME_H_INCLUDED

struct
{
	sf::Clock TimeAsSec;
	sf::Time PrevFrameTime;
	double FrameTime()
	{
		float Sec=PrevFrameTime.asSeconds();
		float TimeX=600;
		double ret=1;
		ret=Sec*TimeX;
		return ret;
	}
}deltaTime;

#endif // FRAMETIME_H_INCLUDED
