############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
open_project pos_software
set_top pos<20,2>
add_files ../../../../../source/repos/SystemCStarter/POS_SYSTEMC/pos.cpp
add_files ../../../../../source/repos/SystemCStarter/POS_SYSTEMC/pos.h
add_files ../../../../../source/repos/SystemCStarter/POS_SYSTEMC/pos_module.cpp
add_files ../../../../../source/repos/SystemCStarter/POS_SYSTEMC/pos_module.h
add_files -tb ../../../../../source/repos/SystemCStarter/POS_SYSTEMC/main.cpp
open_solution "pos_software"
set_part {xc7z020clg484-1} -tool vivado
create_clock -period 8 -name default
#source "./pos_software/pos_software/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
