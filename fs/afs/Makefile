# SPDX-License-Identifier: GPL-2.0
#
# Makefile for Red Hat Linux AFS client.
#

kafs-y := \
	addr_list.o \
	addr_prefs.o \
	callback.o \
	cell.o \
	cm_security.o \
	cmservice.o \
	dir.o \
	dir_edit.o \
	dir_search.o \
	dir_silly.o \
	dynroot.o \
	file.o \
	flock.o \
	fsclient.o \
	fs_operation.o \
	fs_probe.o \
	inode.o \
	main.o \
	misc.o \
	mntpt.o \
	rotate.o \
	rxrpc.o \
	security.o \
	server.o \
	server_list.o \
	super.o \
	validation.o \
	vlclient.o \
	vl_alias.o \
	vl_list.o \
	vl_probe.o \
	vl_rotate.o \
	volume.o \
	write.o \
	xattr.o \
	yfsclient.o

kafs-$(CONFIG_PROC_FS) += proc.o
obj-$(CONFIG_AFS_FS)  := kafs.o
