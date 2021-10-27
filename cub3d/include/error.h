/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 16:25:48 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/19 16:18:58 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define RED "\033[0;31m"
# define RESET "\033[0m"

# define ERR_MUCH_ARGS "Too much arguments !"
# define ERR_FEW_ARGS "Too few arguments !"

# define ERR_EXT_FILE "You must provide a .cub file"
# define ERR_EXT_TEX "Your texture format cannot be used"
# define ERR_SAVE_ARG "Unknown option"

# define ERR_MALLOC "Memory allocation failure"

# define ERR_FILE_OP ".cub file not found"
# define ERR_FILE_READ "Can't read the .cub file properly"

# define ERR_FORM_CUB "Syntax error in the .cub file"
# define ERR_ELEM_FORM "Can't recognize or find one element in the .cub"
# define ERR_ELEM_NBR "Wrong number of elements in the .cub file"
# define ERR_ELEM_CLR "Syntax error with a least one of the color in the .cub"
# define ERR_ELEM_RES "Resolution error"

# define ERR_TEXT_PATH "Can't find the texture"

# define ERR_MAP_CHAR "Too much character"
# define ERR_MAP_CHAR_NF "Character not found"
# define ERR_MAP "Map error"
# define ERR_BMP "Unable to create a bitmap file"

#endif
