/*
 * Copyright (c) 2019 The strace developers.
 * All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#ifndef BASE_NR
# define BASE_NR 0
#endif

[BASE_NR + 424] = { 4,	TD|TS,		"pidfd_send_signal"	},
[BASE_NR + 425] = { 2,	TD,		"io_uring_setup"	},
[BASE_NR + 426] = { 6,	TD|TS,		"io_uring_enter"	},
[BASE_NR + 427] = { 4,	TD|TM,		"io_uring_register"	},
[BASE_NR + 428] = { 3,	TD|TF,			"open_tree"		},
[BASE_NR + 429] = { 5,	TD|TF,		"move_mount"		},
[BASE_NR + 430] = { 2,	TD,			"fsopen"		},
[BASE_NR + 431] = { 5,	TD|TF,			"fsconfig"		},
[BASE_NR + 432] = { 3,	TD,			"fsmount"		},
[BASE_NR + 433] = { 3,	TD|TF,			"fspick"		},
[BASE_NR + 434] = { 2,	TD,		"pidfd_open"		},
[BASE_NR + 435] = { 2,	TP,			"clone3"		},
