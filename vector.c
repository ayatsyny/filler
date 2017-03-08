//
// Created by Andriy Yatsynyak on 3/8/17.
//

static unsigned	distance_point(t_bot *bot, t_piece *piece)
{
	int x;
	int y;

	x = piece.x - bot.x;
	y = piece.y - bot.x;
	x = x * x;
	y = y * y;
	return (x + y);
}

unsigned	ft_sqrt(t_bot *bot, t_piece *piece)
{
	unsigned x;
	unsigned num;

	num = distance_point(bot, piece);
	x = (num/0x3f + 0x3f)>>1;
	x = (a/x + x)>>1;
	x = (a/x + x)>>1;
	return (x);
}