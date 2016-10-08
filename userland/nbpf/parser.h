/*
 *  Copyright (C) 2016 ntop.org
 *
 *      http://www.ntop.org/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesses General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 */


#ifndef BPF_PARSER_H
#define BPF_PARSER_H

#include <stdio.h>
#include <stdarg.h>

#include "nbpf.h"

#ifdef HAVE_NDPI
#include "ndpi_main.h"
#endif

nbpf_node_t *nbpf_create_and(nbpf_node_t *, nbpf_node_t *);
nbpf_node_t *nbpf_create_or(nbpf_node_t *, nbpf_node_t *);
nbpf_node_t *nbpf_create_eth_node(const u_char *, nbpf_qualifiers_t);
nbpf_node_t *nbpf_create_n_node(u_int32_t nn, nbpf_qualifiers_t q);
nbpf_node_t *nbpf_create_host_node(const char *s, nbpf_qualifiers_t q);
nbpf_node_t *nbpf_create_portrange_node(const char *, nbpf_qualifiers_t);
nbpf_node_t *nbpf_create_net_node(const char *, const char *, int, nbpf_qualifiers_t);
nbpf_node_t *nbpf_create_net6_node(const char *, int, nbpf_qualifiers_t);
nbpf_node_t *nbpf_create_proto_node(int);
nbpf_node_t *nbpf_create_vlan_node(int);
nbpf_node_t *nbpf_create_mpls_node(int);
nbpf_node_t *nbpf_create_gtp_node();
nbpf_node_t *nbpf_create_l7_node(u_int32_t, const char *);
void nbpf_create_not(nbpf_node_t *);

void nbpf_lex_init(const char *);
void nbpf_lex_cleanup(void);
void nbpf_syntax_error(char * format, ...);
void nbpf_set_tree_root(nbpf_node_t *n);

int yylex(void);
int yyparse(void);

#endif /* BPF_PARSER_H */