/*
 * scheduler.h
 *
 *  Created on: 07/05/2015
 *      Author: tiago
 */

#ifndef INCLUDE_SCHEDULER_H_
#define INCLUDE_SCHEDULER_H_

#include "list.h"




__BEGIN_SYS

template <typename T, typename R = typename T::Criterion>
class Scheduler : public Scheduling_List<T>{
	typedef Scheduling_List<T> test;
	void insert(T * obj){

	}

};

__END_SYS
#endif /* INCLUDE_SCHEDULER_H_ */
