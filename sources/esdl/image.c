/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esdl_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:57:18 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/17 18:55:21 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static SDL_Surface	*create_fallback_texture(SDL_Surface *surf)
{
	SDL_Rect		rect;

	rect.x = 0;
	rect.y = 0;
	rect.w = 32;
	rect.h = 32;
	surf = esdl_create_surface(32, 32);
	esdl_draw_filled_square(surf, &rect, 0xff69b4ff, NULL);
	return (surf);
}

SDL_Texture			*esdl_load_texture(SDL_Renderer *render, \
	const char *path, int *w, int *h)
{
	SDL_Surface		*surf;
	SDL_Texture		*tex;

	surf = SDL_LoadBMP(path);
	if (w != NULL)
		*w = surf->w;
	if (h != NULL)
		*h = surf->h;
	if (!surf)
	{
		ft_printf("Error while loading texture : \"%s\", \
			fallback texture created\n", path);
		surf = create_fallback_texture(surf);
	}
	tex = SDL_CreateTextureFromSurface(render, surf);
	SDL_FreeSurface(surf);
	return (tex);
}
