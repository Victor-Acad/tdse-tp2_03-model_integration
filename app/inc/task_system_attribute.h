/*
 * Copyright (c) 2023 Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * @file   : task_system_attribute.h
 * @date   : Set 26, 2023
 * @author : Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>
 * @version	v1.0.0
 */

#ifndef TASK_INC_TASK_SYSTEM_ATTRIBUTE_H_
#define TASK_INC_TASK_SYSTEM_ATTRIBUTE_H_

/********************** CPP guard ********************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************** inclusions *******************************************/

/********************** macros ***********************************************/

/********************** typedef **********************************************/
/* System Statechart - State Transition Table */
/* 	------------------------+-----------------------+-----------------------+-----------------------+------------------------
 * 	| Current               | Event                 |                       | Next                  |                       |
 * 	| State                 | (Parameters)          | [Guard]               | State                 | Actions               |
 * 	|=======================+=======================+=======================+=======================+=======================|
 * 	| ST_SYS_XX_IDLE        | EV_SYS_XX_ACTIVE      |                       | ST_SYS_XX_ACTIVE      | put_event_t.._actuator|
 * 	|                       |                       |                       |                       | (event, identifier)   |
 * 	|-----------------------+-----------------------+-----------------------+-----------------------+-----------------------|
 * 	| ST_SYS_XX_ACTIVE      | EV_SYS_XX_IDLE        |                       | ST_SYS_XX_IDLE        | put_event_t.._actuator|
 * 	|                       |                       |                       |                       | (event, identifier)   |
 * 	------------------------+-----------------------+-----------------------+-----------------------+------------------------
 */

/* System Model for Parking Lot Entrance (Taller de Sistemas Embebidos TP 2).
 *
 *                   |------------------------- Go back to initial state ----------------------------|
 *                   v                                                                               |
 * ST_SYS_XX_WAIT_VEHICLE --> Wait for 'EV_SYS_XX_LOOP_DETECTOR_UP' or 'EV_SYS_XX_MANUAL_UP' -       |
 *                                                                                           |       |
 * |------------------------------------------------------------------------------------------       |
 * v                                                                                                 |
 * ST_SYS_XX_WAIT_BARRIER_RAISE --> Wait for 'EV_SYS_XX_VERT_LIMIT_UP' -----------------------       |
 *                                                                                           |       |
 * |------------------------------------------------------------------------------------------       |
 * v                                                                                                 |
 * ST_SYS_XX_WAIT_VEHICLE_PASS --> Wait for 'EV_SYS_XX_IR_DOWN' or 'EV_SYS_XX_MANUAL_UP' -----       |
 *                                                                                           |       |
 * |------------------------------------------------------------------------------------------       |
 * v                                                                                                 |
 * ST_SYS_XX_WAIT_BARRIER_LOWER --> Wait for 'EV_SYS_XX_HORZ_LIMIT_UP' -------------------------------
 *
 */

/* Events to excite Task System */
typedef enum task_system_ev {EV_SYS_XX_LOOP_DETECTOR_UP,
							 EV_SYS_XX_VERT_LIMIT_UP,
							 EV_SYS_XX_IR_DOWN,
							 EV_SYS_XX_HORZ_LIMIT_UP,
							 EV_SYS_XX_MANUAL_UP,
                             EV_SYS_XX_DUMMY} task_system_ev_t;

/* State of Task System */
typedef enum task_system_st {ST_SYS_XX_WAIT_VEHICLE,
							 ST_SYS_XX_WAIT_BARRIER_RAISE,
							 ST_SYS_XX_WAIT_VEHICLE_PASS,
							 ST_SYS_XX_WAIT_BARRIER_LOWER} task_system_st_t;

typedef struct
{
	uint32_t			tick;
	task_system_st_t	state;
	task_system_ev_t	event;
	bool				flag;
} task_system_dta_t;

/********************** external data declaration ****************************/
extern task_system_dta_t task_system_dta;

/********************** external functions declaration ***********************/

/********************** End of CPP guard *************************************/
#ifdef __cplusplus
}
#endif

#endif /* TASK_INC_TASK_SYSTEM_ATTRIBUTE_H_ */

/********************** end of file ******************************************/
