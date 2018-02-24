# Distributed Systems Engineer Challenge

## Instructions

`$ make && ./MesosphereScheduler`

## Overview

My solution consists of four modules/pieces:
1. Node - Contains information on how many resources are available
2. Job  - Contains information about the job request to be submitted to the scheduler
3. Scheduler - Contains the core logic on resource allocation to incoming jobs
4. Main/Driver - Creates a random list of jobs and nodes and schedules resources on a per job basis. 

* Scheduling logic: Among the nodes available, find the node where the difference between resource available at the node and the job's resource request is the least.

Due to lack of time from my side, I have made a few assumptions. 
1. `main.cpp` - Simulates the stream of requests at a time instant. The nodes and jobs have their state randomly generated.
2. Scheduler is given a collection of nodes and the jobs are submitted to the scheduler one at a time.

If more time was available, I could've introduced a threaded environment where ending of jobs could trigger the node to release resources.
Also, I have not stored information about jobs running in a node. Ideally, an unordered_map <node_id, list<Job> jobs> could be used for this. 

I could've used a priority queue with <timestep, event> as the key for an event-based model. At every timestep, I should make sure that the resources are released before a job is considered for scheduling.