#include "connect_four.h"

int	animation(void *param)
{
	int x, y;


	(void) param;
	mlx_mouse_get_pos(data()->mlx, data()->win, &x, &y);
	if (data()->piece && !data()->piece->is_free)
		set_position_piece((x / PIECE_RES));
	board_render();
	return (1);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	data()->turn = 1;
	data()->mlx = mlx_init();
	data()->win = mlx_new_window(data()->mlx, WINDOW_RES, WINDOW_RES, "Connect 4");
	image_load();
	mlx_loop_hook(data()->mlx, animation, &data);
	mlx_mouse_hook(data()->win, mouse, data);
	mlx_loop(data()->mlx);
}