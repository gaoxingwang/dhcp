/* tables.c

   Tables of information... */

/*
 * Copyright (c) 1996-1999 Internet Software Consortium.
 * Use is subject to license terms which appear in the file named
 * ISC-LICENSE that should have accompanied this file when you
 * received it.   If a file named ISC-LICENSE did not accompany this
 * file, or you are not sure the one you have is correct, you may
 * obtain an applicable copy of the license at:
 *
 *             http://www.isc.org/isc-license-1.0.html. 
 *
 * This file is part of the ISC DHCP distribution.   The documentation
 * associated with this file is listed in the file DOCUMENTATION,
 * included in the top-level directory of this release.
 *
 * Support and other services are available for ISC products - see
 * http://www.isc.org for more information.
 */

#ifndef lint
static char copyright[] =
"$Id: tables.c,v 1.35 2000/01/26 14:55:34 mellon Exp $ Copyright (c) 1995, 1996, 1998, 1999 The Internet Software Consortium.  All rights reserved.\n";
#endif /* not lint */

#include "dhcpd.h"

/* DHCP Option names, formats and codes, from RFC1533.

   Format codes:

   e - end of data
   I - IP address
   l - 32-bit signed integer
   L - 32-bit unsigned integer
   s - 16-bit signed integer
   S - 16-bit unsigned integer
   b - 8-bit signed integer
   B - 8-bit unsigned integer
   t - ASCII text
   f - flag (true or false)
   A - array of whatever precedes (e.g., IA means array of IP addresses)
   U - name of an option space (universe)
   F - implicit flag - the presence of the option indicates that the
       flag is true.
*/

struct universe dhcp_universe;
struct option dhcp_options [256] = {
	{ "pad", "",					&dhcp_universe, 0 },
	{ "subnet-mask", "I",				&dhcp_universe, 1 },
	{ "time-offset", "l",				&dhcp_universe, 2 },
	{ "routers", "IA",				&dhcp_universe, 3 },
	{ "time-servers", "IA",				&dhcp_universe, 4 },
	{ "ien116-name-servers", "IA",			&dhcp_universe, 5 },
	{ "domain-name-servers", "IA",			&dhcp_universe, 6 },
	{ "log-servers", "IA",				&dhcp_universe, 7 },
	{ "cookie-servers", "IA",			&dhcp_universe, 8 },
	{ "lpr-servers", "IA",				&dhcp_universe, 9 },
	{ "impress-servers", "IA",			&dhcp_universe, 10 },
	{ "resource-location-servers", "IA",		&dhcp_universe, 11 },
	{ "host-name", "X",				&dhcp_universe, 12 },
	{ "boot-size", "S",				&dhcp_universe, 13 },
	{ "merit-dump", "t",				&dhcp_universe, 14 },
	{ "domain-name", "t",				&dhcp_universe, 15 },
	{ "swap-server", "I",				&dhcp_universe, 16 },
	{ "root-path", "t",				&dhcp_universe, 17 },
	{ "extensions-path", "t",			&dhcp_universe, 18 },
	{ "ip-forwarding", "f",				&dhcp_universe, 19 },
	{ "non-local-source-routing", "f",		&dhcp_universe, 20 },
	{ "policy-filter", "IIA",			&dhcp_universe, 21 },
	{ "max-dgram-reassembly", "S",			&dhcp_universe, 22 },
	{ "default-ip-ttl", "B",			&dhcp_universe, 23 },
	{ "path-mtu-aging-timeout", "L",		&dhcp_universe, 24 },
	{ "path-mtu-plateau-table", "SA",		&dhcp_universe, 25 },
	{ "interface-mtu", "S",				&dhcp_universe, 26 },
	{ "all-subnets-local", "f",			&dhcp_universe, 27 },
	{ "broadcast-address", "I",			&dhcp_universe, 28 },
	{ "perform-mask-discovery", "f",		&dhcp_universe, 29 },
	{ "mask-supplier", "f",				&dhcp_universe, 30 },
	{ "router-discovery", "f",			&dhcp_universe, 31 },
	{ "router-solicitation-address", "I",		&dhcp_universe, 32 },
	{ "static-routes", "IIA",			&dhcp_universe, 33 },
	{ "trailer-encapsulation", "f",			&dhcp_universe, 34 },
	{ "arp-cache-timeout", "L",			&dhcp_universe, 35 },
	{ "ieee802-3-encapsulation", "f",		&dhcp_universe, 36 },
	{ "default-tcp-ttl", "B",			&dhcp_universe, 37 },
	{ "tcp-keepalive-interval", "L",		&dhcp_universe, 38 },
	{ "tcp-keepalive-garbage", "f",			&dhcp_universe, 39 },
	{ "nis-domain", "t",				&dhcp_universe, 40 },
	{ "nis-servers", "IA",				&dhcp_universe, 41 },
	{ "ntp-servers", "IA",				&dhcp_universe, 42 },
	{ "vendor-encapsulated-options", "X",		&dhcp_universe, 43 },
	{ "netbios-name-servers", "IA",			&dhcp_universe, 44 },
	{ "netbios-dd-server", "IA",			&dhcp_universe, 45 },
	{ "netbios-node-type", "B",			&dhcp_universe, 46 },
	{ "netbios-scope", "t",				&dhcp_universe, 47 },
	{ "font-servers", "IA",				&dhcp_universe, 48 },
	{ "x-display-manager", "IA",			&dhcp_universe, 49 },
	{ "dhcp-requested-address", "I",		&dhcp_universe, 50 },
	{ "dhcp-lease-time", "L",			&dhcp_universe, 51 },
	{ "dhcp-option-overload", "B",			&dhcp_universe, 52 },
	{ "dhcp-message-type", "B",			&dhcp_universe, 53 },
	{ "dhcp-server-identifier", "I",		&dhcp_universe, 54 },
	{ "dhcp-parameter-request-list", "BA",		&dhcp_universe, 55 },
	{ "dhcp-message", "t",				&dhcp_universe, 56 },
	{ "dhcp-max-message-size", "S",			&dhcp_universe, 57 },
	{ "dhcp-renewal-time", "L",			&dhcp_universe, 58 },
	{ "dhcp-rebinding-time", "L",			&dhcp_universe, 59 },
	{ "vendor-class-identifier", "X",		&dhcp_universe, 60 },
	{ "dhcp-client-identifier", "X",		&dhcp_universe, 61 },
	{ "nwip-domain", "X",				&dhcp_universe, 62 },
	{ "nwip-suboptions", "X",			&dhcp_universe, 63 },
	{ "nisplus-domain", "t",			&dhcp_universe, 64 },
	{ "nisplus-servers", "IA",			&dhcp_universe, 65 },
	{ "tftp-server-name", "t",			&dhcp_universe, 66 },
	{ "bootfile-name", "t",				&dhcp_universe, 67 },
	{ "mobile-ip-home-agent", "IA",			&dhcp_universe, 68 },
	{ "smtp-server", "IA",				&dhcp_universe, 69 },
	{ "pop-server", "IA",				&dhcp_universe, 70 },
	{ "nntp-server", "IA",				&dhcp_universe, 71 },
	{ "www-server", "IA",				&dhcp_universe, 72 },
	{ "finger-server", "IA",			&dhcp_universe, 73 },
	{ "irc-server", "IA",				&dhcp_universe, 74 },
	{ "streettalk-server", "IA",			&dhcp_universe, 75 },
	{ "streettalk-directory-assistance-server", "IA", &dhcp_universe, 76 },
	{ "user-class", "t",				&dhcp_universe, 77 },
	{ "option-78", "X",				&dhcp_universe, 78 },
	{ "option-79", "X",				&dhcp_universe, 79 },
	{ "option-80", "X",				&dhcp_universe, 80 },
	{ "option-81", "X",				&dhcp_universe, 81 },
	{ "option-82", "X",				&dhcp_universe, 82 },
	{ "option-83", "X",				&dhcp_universe, 83 },
	{ "option-84", "X",				&dhcp_universe, 84 },
	{ "nds-servers", "IA",				&dhcp_universe, 85 },
	{ "nds-tree-name", "X",				&dhcp_universe, 86 },
	{ "nds-context", "X",				&dhcp_universe, 87 },
	{ "option-88", "X",				&dhcp_universe, 88 },
	{ "option-89", "X",				&dhcp_universe, 89 },
	{ "option-90", "X",				&dhcp_universe, 90 },
	{ "option-91", "X",				&dhcp_universe, 91 },
	{ "option-92", "X",				&dhcp_universe, 92 },
	{ "option-93", "X",				&dhcp_universe, 93 },
	{ "option-94", "X",				&dhcp_universe, 94 },
	{ "option-95", "X",				&dhcp_universe, 95 },
	{ "option-96", "X",				&dhcp_universe, 96 },
	{ "option-97", "X",				&dhcp_universe, 97 },
	{ "uap-servers", "t",				&dhcp_universe, 98 },
	{ "option-99", "X",				&dhcp_universe, 99 },
	{ "option-100", "X",				&dhcp_universe, 100 },
	{ "option-101", "X",				&dhcp_universe, 101 },
	{ "option-102", "X",				&dhcp_universe, 102 },
	{ "option-103", "X",				&dhcp_universe, 103 },
	{ "option-104", "X",				&dhcp_universe, 104 },
	{ "option-105", "X",				&dhcp_universe, 105 },
	{ "option-106", "X",				&dhcp_universe, 106 },
	{ "option-107", "X",				&dhcp_universe, 107 },
	{ "option-108", "X",				&dhcp_universe, 108 },
	{ "option-109", "X",				&dhcp_universe, 109 },
	{ "option-110", "X",				&dhcp_universe, 110 },
	{ "option-111", "X",				&dhcp_universe, 111 },
	{ "option-112", "X",				&dhcp_universe, 112 },
	{ "option-113", "X",				&dhcp_universe, 113 },
	{ "option-114", "X",				&dhcp_universe, 114 },
	{ "option-115", "X",				&dhcp_universe, 115 },
	{ "option-116", "X",				&dhcp_universe, 116 },
	{ "option-117", "X",				&dhcp_universe, 117 },
	{ "option-118", "X",				&dhcp_universe, 118 },
	{ "option-119", "X",				&dhcp_universe, 119 },
	{ "option-120", "X",				&dhcp_universe, 120 },
	{ "option-121", "X",				&dhcp_universe, 121 },
	{ "option-122", "X",				&dhcp_universe, 122 },
	{ "option-123", "X",				&dhcp_universe, 123 },
	{ "option-124", "X",				&dhcp_universe, 124 },
	{ "option-125", "X",				&dhcp_universe, 125 },
	{ "option-126", "X",				&dhcp_universe, 126 },
	{ "option-127", "X",				&dhcp_universe, 127 },
	{ "option-128", "X",				&dhcp_universe, 128 },
	{ "option-129", "X",				&dhcp_universe, 129 },
	{ "option-130", "X",				&dhcp_universe, 130 },
	{ "option-131", "X",				&dhcp_universe, 131 },
	{ "option-132", "X",				&dhcp_universe, 132 },
	{ "option-133", "X",				&dhcp_universe, 133 },
	{ "option-134", "X",				&dhcp_universe, 134 },
	{ "option-135", "X",				&dhcp_universe, 135 },
	{ "option-136", "X",				&dhcp_universe, 136 },
	{ "option-137", "X",				&dhcp_universe, 137 },
	{ "option-138", "X",				&dhcp_universe, 138 },
	{ "option-139", "X",				&dhcp_universe, 139 },
	{ "option-140", "X",				&dhcp_universe, 140 },
	{ "option-141", "X",				&dhcp_universe, 141 },
	{ "option-142", "X",				&dhcp_universe, 142 },
	{ "option-143", "X",				&dhcp_universe, 143 },
	{ "option-144", "X",				&dhcp_universe, 144 },
	{ "option-145", "X",				&dhcp_universe, 145 },
	{ "option-146", "X",				&dhcp_universe, 146 },
	{ "option-147", "X",				&dhcp_universe, 147 },
	{ "option-148", "X",				&dhcp_universe, 148 },
	{ "option-149", "X",				&dhcp_universe, 149 },
	{ "option-150", "X",				&dhcp_universe, 150 },
	{ "option-151", "X",				&dhcp_universe, 151 },
	{ "option-152", "X",				&dhcp_universe, 152 },
	{ "option-153", "X",				&dhcp_universe, 153 },
	{ "option-154", "X",				&dhcp_universe, 154 },
	{ "option-155", "X",				&dhcp_universe, 155 },
	{ "option-156", "X",				&dhcp_universe, 156 },
	{ "option-157", "X",				&dhcp_universe, 157 },
	{ "option-158", "X",				&dhcp_universe, 158 },
	{ "option-159", "X",				&dhcp_universe, 159 },
	{ "option-160", "X",				&dhcp_universe, 160 },
	{ "option-161", "X",				&dhcp_universe, 161 },
	{ "option-162", "X",				&dhcp_universe, 162 },
	{ "option-163", "X",				&dhcp_universe, 163 },
	{ "option-164", "X",				&dhcp_universe, 164 },
	{ "option-165", "X",				&dhcp_universe, 165 },
	{ "option-166", "X",				&dhcp_universe, 166 },
	{ "option-167", "X",				&dhcp_universe, 167 },
	{ "option-168", "X",				&dhcp_universe, 168 },
	{ "option-169", "X",				&dhcp_universe, 169 },
	{ "option-170", "X",				&dhcp_universe, 170 },
	{ "option-171", "X",				&dhcp_universe, 171 },
	{ "option-172", "X",				&dhcp_universe, 172 },
	{ "option-173", "X",				&dhcp_universe, 173 },
	{ "option-174", "X",				&dhcp_universe, 174 },
	{ "option-175", "X",				&dhcp_universe, 175 },
	{ "option-176", "X",				&dhcp_universe, 176 },
	{ "option-177", "X",				&dhcp_universe, 177 },
	{ "option-178", "X",				&dhcp_universe, 178 },
	{ "option-179", "X",				&dhcp_universe, 179 },
	{ "option-180", "X",				&dhcp_universe, 180 },
	{ "option-181", "X",				&dhcp_universe, 181 },
	{ "option-182", "X",				&dhcp_universe, 182 },
	{ "option-183", "X",				&dhcp_universe, 183 },
	{ "option-184", "X",				&dhcp_universe, 184 },
	{ "option-185", "X",				&dhcp_universe, 185 },
	{ "option-186", "X",				&dhcp_universe, 186 },
	{ "option-187", "X",				&dhcp_universe, 187 },
	{ "option-188", "X",				&dhcp_universe, 188 },
	{ "option-189", "X",				&dhcp_universe, 189 },
	{ "option-190", "X",				&dhcp_universe, 190 },
	{ "option-191", "X",				&dhcp_universe, 191 },
	{ "option-192", "X",				&dhcp_universe, 192 },
	{ "option-193", "X",				&dhcp_universe, 193 },
	{ "option-194", "X",				&dhcp_universe, 194 },
	{ "option-195", "X",				&dhcp_universe, 195 },
	{ "option-196", "X",				&dhcp_universe, 196 },
	{ "option-197", "X",				&dhcp_universe, 197 },
	{ "option-198", "X",				&dhcp_universe, 198 },
	{ "option-199", "X",				&dhcp_universe, 199 },
	{ "option-200", "X",				&dhcp_universe, 200 },
	{ "option-201", "X",				&dhcp_universe, 201 },
	{ "option-202", "X",				&dhcp_universe, 202 },
	{ "option-203", "X",				&dhcp_universe, 203 },
	{ "option-204", "X",				&dhcp_universe, 204 },
	{ "option-205", "X",				&dhcp_universe, 205 },
	{ "option-206", "X",				&dhcp_universe, 206 },
	{ "option-207", "X",				&dhcp_universe, 207 },
	{ "option-208", "X",				&dhcp_universe, 208 },
	{ "option-209", "X",				&dhcp_universe, 209 },
	{ "authenticate", "X",				&dhcp_universe, 210 },
	{ "option-211", "X",				&dhcp_universe, 211 },
	{ "option-212", "X",				&dhcp_universe, 212 },
	{ "option-213", "X",				&dhcp_universe, 213 },
	{ "option-214", "X",				&dhcp_universe, 214 },
	{ "option-215", "X",				&dhcp_universe, 215 },
	{ "option-216", "X",				&dhcp_universe, 216 },
	{ "option-217", "X",				&dhcp_universe, 217 },
	{ "option-218", "X",				&dhcp_universe, 218 },
	{ "option-219", "X",				&dhcp_universe, 219 },
	{ "option-220", "X",				&dhcp_universe, 220 },
	{ "option-221", "X",				&dhcp_universe, 221 },
	{ "option-222", "X",				&dhcp_universe, 222 },
	{ "option-223", "X",				&dhcp_universe, 223 },
	{ "option-224", "X",				&dhcp_universe, 224 },
	{ "option-225", "X",				&dhcp_universe, 225 },
	{ "option-226", "X",				&dhcp_universe, 226 },
	{ "option-227", "X",				&dhcp_universe, 227 },
	{ "option-228", "X",				&dhcp_universe, 228 },
	{ "option-229", "X",				&dhcp_universe, 229 },
	{ "option-230", "X",				&dhcp_universe, 230 },
	{ "option-231", "X",				&dhcp_universe, 231 },
	{ "option-232", "X",				&dhcp_universe, 232 },
	{ "option-233", "X",				&dhcp_universe, 233 },
	{ "option-234", "X",				&dhcp_universe, 234 },
	{ "option-235", "X",				&dhcp_universe, 235 },
	{ "option-236", "X",				&dhcp_universe, 236 },
	{ "option-237", "X",				&dhcp_universe, 237 },
	{ "option-238", "X",				&dhcp_universe, 238 },
	{ "option-239", "X",				&dhcp_universe, 239 },
	{ "option-240", "X",				&dhcp_universe, 240 },
	{ "option-241", "X",				&dhcp_universe, 241 },
	{ "option-242", "X",				&dhcp_universe, 242 },
	{ "option-243", "X",				&dhcp_universe, 243 },
	{ "option-244", "X",				&dhcp_universe, 244 },
	{ "option-245", "X",				&dhcp_universe, 245 },
	{ "option-246", "X",				&dhcp_universe, 246 },
	{ "option-247", "X",				&dhcp_universe, 247 },
	{ "option-248", "X",				&dhcp_universe, 248 },
	{ "option-249", "X",				&dhcp_universe, 249 },
	{ "option-250", "X",				&dhcp_universe, 250 },
	{ "option-251", "X",				&dhcp_universe, 251 },
	{ "option-252", "X",				&dhcp_universe, 252 },
	{ "option-253", "X",				&dhcp_universe, 253 },
	{ "option-254", "X",				&dhcp_universe, 254 },
	{ "option-end", "e",				&dhcp_universe, 255 },
};

struct universe nwip_universe;
struct option nwip_options [256] = {
	{ "pad", "",					&nwip_universe, 0 },
	{ "illegal-1", "",				&nwip_universe, 1 },
	{ "illegal-2", "",				&nwip_universe, 2 },
	{ "illegal-3", "",				&nwip_universe, 3 },
	{ "illegal-4", "",				&nwip_universe, 4 },
	{ "nsq-broadcast", "f",				&nwip_universe, 5 },
	{ "preferred-dss", "IA",			&nwip_universe, 6 },
	{ "nearest-nwip-server", "IA",			&nwip_universe, 7 },
	{ "autoretries", "B",				&nwip_universe, 8 },
	{ "autoretry-secs", "B",			&nwip_universe, 9 },
	{ "nwip-1-1", "f",				&nwip_universe, 10 },
	{ "primary-dss", "I",				&nwip_universe, 11 },
	{ "option-12", "X",				&nwip_universe, 12 },
	{ "option-13", "X",				&nwip_universe, 13 },
	{ "option-14", "X",				&nwip_universe, 14 },
	{ "option-15", "X",				&nwip_universe, 15 },
	{ "option-16", "X",				&nwip_universe, 16 },
	{ "option-17", "X",				&nwip_universe, 17 },
	{ "option-18", "X",				&nwip_universe, 18 },
	{ "option-19", "X",				&nwip_universe, 19 },
	{ "option-20", "X",				&nwip_universe, 20 },
	{ "option-21", "X",				&nwip_universe, 21 },
	{ "option-22", "X",				&nwip_universe, 22 },
	{ "option-23", "X",				&nwip_universe, 23 },
	{ "option-24", "X",				&nwip_universe, 24 },
	{ "option-25", "X",				&nwip_universe, 25 },
	{ "option-26", "X",				&nwip_universe, 26 },
	{ "option-27", "X",				&nwip_universe, 27 },
	{ "option-28", "X",				&nwip_universe, 28 },
	{ "option-29", "X",				&nwip_universe, 29 },
	{ "option-30", "X",				&nwip_universe, 30 },
	{ "option-31", "X",				&nwip_universe, 31 },
	{ "option-32", "X",				&nwip_universe, 32 },
	{ "option-33", "X",				&nwip_universe, 33 },
	{ "option-34", "X",				&nwip_universe, 34 },
	{ "option-35", "X",				&nwip_universe, 35 },
	{ "option-36", "X",				&nwip_universe, 36 },
	{ "option-37", "X",				&nwip_universe, 37 },
	{ "option-38", "X",				&nwip_universe, 38 },
	{ "option-39", "X",				&nwip_universe, 39 },
	{ "option-40", "X",				&nwip_universe, 40 },
	{ "option-41", "X",				&nwip_universe, 41 },
	{ "option-42", "X",				&nwip_universe, 42 },
	{ "option-43", "X",				&nwip_universe, 43 },
	{ "option-44", "X",				&nwip_universe, 44 },
	{ "option-45", "X",				&nwip_universe, 45 },
	{ "option-46", "X",				&nwip_universe, 46 },
	{ "option-47", "X",				&nwip_universe, 47 },
	{ "option-48", "X",				&nwip_universe, 48 },
	{ "option-49", "X",				&nwip_universe, 49 },
	{ "option-50", "X",				&nwip_universe, 50 },
	{ "option-51", "X",				&nwip_universe, 51 },
	{ "option-52", "X",				&nwip_universe, 52 },
	{ "option-53", "X",				&nwip_universe, 53 },
	{ "option-54", "X",				&nwip_universe, 54 },
	{ "option-55", "X",				&nwip_universe, 55 },
	{ "option-56", "X",				&nwip_universe, 56 },
	{ "option-57", "X",				&nwip_universe, 57 },
	{ "option-58", "X",				&nwip_universe, 58 },
	{ "option-59", "X",				&nwip_universe, 59 },
	{ "option-60", "X",				&nwip_universe, 60 },
	{ "option-61", "X",				&nwip_universe, 61 },
	{ "option-62", "X",				&nwip_universe, 62 },
	{ "option-63", "X",				&nwip_universe, 63 },
	{ "option-64", "X",				&nwip_universe, 64 },
	{ "option-65", "X",				&nwip_universe, 65 },
	{ "option-66", "X",				&nwip_universe, 66 },
	{ "option-67", "X",				&nwip_universe, 67 },
	{ "option-68", "X",				&nwip_universe, 68 },
	{ "option-69", "X",				&nwip_universe, 69 },
	{ "option-70", "X",				&nwip_universe, 70 },
	{ "option-71", "X",				&nwip_universe, 71 },
	{ "option-72", "X",				&nwip_universe, 72 },
	{ "option-73", "X",				&nwip_universe, 73 },
	{ "option-74", "X",				&nwip_universe, 74 },
	{ "option-75", "X",				&nwip_universe, 75 },
	{ "option-76", "X",				&nwip_universe, 76 },
	{ "option-77", "X",				&nwip_universe, 77 },
	{ "option-78", "X",				&nwip_universe, 78 },
	{ "option-79", "X",				&nwip_universe, 79 },
	{ "option-80", "X",				&nwip_universe, 80 },
	{ "option-81", "X",				&nwip_universe, 81 },
	{ "option-82", "X",				&nwip_universe, 82 },
	{ "option-83", "X",				&nwip_universe, 83 },
	{ "option-84", "X",				&nwip_universe, 84 },
	{ "option-85", "X",				&nwip_universe, 85 },
	{ "option-86", "X",				&nwip_universe, 86 },
	{ "option-87", "X",				&nwip_universe, 87 },
	{ "option-88", "X",				&nwip_universe, 88 },
	{ "option-89", "X",				&nwip_universe, 89 },
	{ "option-90", "X",				&nwip_universe, 90 },
	{ "option-91", "X",				&nwip_universe, 91 },
	{ "option-92", "X",				&nwip_universe, 92 },
	{ "option-93", "X",				&nwip_universe, 93 },
	{ "option-94", "X",				&nwip_universe, 94 },
	{ "option-95", "X",				&nwip_universe, 95 },
	{ "option-96", "X",				&nwip_universe, 96 },
	{ "option-97", "X",				&nwip_universe, 97 },
	{ "option-98", "X",				&nwip_universe, 98 },
	{ "option-99", "X",				&nwip_universe, 99 },
	{ "option-100", "X",				&nwip_universe, 100 },
	{ "option-101", "X",				&nwip_universe, 101 },
	{ "option-102", "X",				&nwip_universe, 102 },
	{ "option-103", "X",				&nwip_universe, 103 },
	{ "option-104", "X",				&nwip_universe, 104 },
	{ "option-105", "X",				&nwip_universe, 105 },
	{ "option-106", "X",				&nwip_universe, 106 },
	{ "option-107", "X",				&nwip_universe, 107 },
	{ "option-108", "X",				&nwip_universe, 108 },
	{ "option-109", "X",				&nwip_universe, 109 },
	{ "option-110", "X",				&nwip_universe, 110 },
	{ "option-111", "X",				&nwip_universe, 111 },
	{ "option-112", "X",				&nwip_universe, 112 },
	{ "option-113", "X",				&nwip_universe, 113 },
	{ "option-114", "X",				&nwip_universe, 114 },
	{ "option-115", "X",				&nwip_universe, 115 },
	{ "option-116", "X",				&nwip_universe, 116 },
	{ "option-117", "X",				&nwip_universe, 117 },
	{ "option-118", "X",				&nwip_universe, 118 },
	{ "option-119", "X",				&nwip_universe, 119 },
	{ "option-120", "X",				&nwip_universe, 120 },
	{ "option-121", "X",				&nwip_universe, 121 },
	{ "option-122", "X",				&nwip_universe, 122 },
	{ "option-123", "X",				&nwip_universe, 123 },
	{ "option-124", "X",				&nwip_universe, 124 },
	{ "option-125", "X",				&nwip_universe, 125 },
	{ "option-126", "X",				&nwip_universe, 126 },
	{ "option-127", "X",				&nwip_universe, 127 },
	{ "option-128", "X",				&nwip_universe, 128 },
	{ "option-129", "X",				&nwip_universe, 129 },
	{ "option-130", "X",				&nwip_universe, 130 },
	{ "option-131", "X",				&nwip_universe, 131 },
	{ "option-132", "X",				&nwip_universe, 132 },
	{ "option-133", "X",				&nwip_universe, 133 },
	{ "option-134", "X",				&nwip_universe, 134 },
	{ "option-135", "X",				&nwip_universe, 135 },
	{ "option-136", "X",				&nwip_universe, 136 },
	{ "option-137", "X",				&nwip_universe, 137 },
	{ "option-138", "X",				&nwip_universe, 138 },
	{ "option-139", "X",				&nwip_universe, 139 },
	{ "option-140", "X",				&nwip_universe, 140 },
	{ "option-141", "X",				&nwip_universe, 141 },
	{ "option-142", "X",				&nwip_universe, 142 },
	{ "option-143", "X",				&nwip_universe, 143 },
	{ "option-144", "X",				&nwip_universe, 144 },
	{ "option-145", "X",				&nwip_universe, 145 },
	{ "option-146", "X",				&nwip_universe, 146 },
	{ "option-147", "X",				&nwip_universe, 147 },
	{ "option-148", "X",				&nwip_universe, 148 },
	{ "option-149", "X",				&nwip_universe, 149 },
	{ "option-150", "X",				&nwip_universe, 150 },
	{ "option-151", "X",				&nwip_universe, 151 },
	{ "option-152", "X",				&nwip_universe, 152 },
	{ "option-153", "X",				&nwip_universe, 153 },
	{ "option-154", "X",				&nwip_universe, 154 },
	{ "option-155", "X",				&nwip_universe, 155 },
	{ "option-156", "X",				&nwip_universe, 156 },
	{ "option-157", "X",				&nwip_universe, 157 },
	{ "option-158", "X",				&nwip_universe, 158 },
	{ "option-159", "X",				&nwip_universe, 159 },
	{ "option-160", "X",				&nwip_universe, 160 },
	{ "option-161", "X",				&nwip_universe, 161 },
	{ "option-162", "X",				&nwip_universe, 162 },
	{ "option-163", "X",				&nwip_universe, 163 },
	{ "option-164", "X",				&nwip_universe, 164 },
	{ "option-165", "X",				&nwip_universe, 165 },
	{ "option-166", "X",				&nwip_universe, 166 },
	{ "option-167", "X",				&nwip_universe, 167 },
	{ "option-168", "X",				&nwip_universe, 168 },
	{ "option-169", "X",				&nwip_universe, 169 },
	{ "option-170", "X",				&nwip_universe, 170 },
	{ "option-171", "X",				&nwip_universe, 171 },
	{ "option-172", "X",				&nwip_universe, 172 },
	{ "option-173", "X",				&nwip_universe, 173 },
	{ "option-174", "X",				&nwip_universe, 174 },
	{ "option-175", "X",				&nwip_universe, 175 },
	{ "option-176", "X",				&nwip_universe, 176 },
	{ "option-177", "X",				&nwip_universe, 177 },
	{ "option-178", "X",				&nwip_universe, 178 },
	{ "option-179", "X",				&nwip_universe, 179 },
	{ "option-180", "X",				&nwip_universe, 180 },
	{ "option-181", "X",				&nwip_universe, 181 },
	{ "option-182", "X",				&nwip_universe, 182 },
	{ "option-183", "X",				&nwip_universe, 183 },
	{ "option-184", "X",				&nwip_universe, 184 },
	{ "option-185", "X",				&nwip_universe, 185 },
	{ "option-186", "X",				&nwip_universe, 186 },
	{ "option-187", "X",				&nwip_universe, 187 },
	{ "option-188", "X",				&nwip_universe, 188 },
	{ "option-189", "X",				&nwip_universe, 189 },
	{ "option-190", "X",				&nwip_universe, 190 },
	{ "option-191", "X",				&nwip_universe, 191 },
	{ "option-192", "X",				&nwip_universe, 192 },
	{ "option-193", "X",				&nwip_universe, 193 },
	{ "option-194", "X",				&nwip_universe, 194 },
	{ "option-195", "X",				&nwip_universe, 195 },
	{ "option-196", "X",				&nwip_universe, 196 },
	{ "option-197", "X",				&nwip_universe, 197 },
	{ "option-198", "X",				&nwip_universe, 198 },
	{ "option-199", "X",				&nwip_universe, 199 },
	{ "option-200", "X",				&nwip_universe, 200 },
	{ "option-201", "X",				&nwip_universe, 201 },
	{ "option-202", "X",				&nwip_universe, 202 },
	{ "option-203", "X",				&nwip_universe, 203 },
	{ "option-204", "X",				&nwip_universe, 204 },
	{ "option-205", "X",				&nwip_universe, 205 },
	{ "option-206", "X",				&nwip_universe, 206 },
	{ "option-207", "X",				&nwip_universe, 207 },
	{ "option-208", "X",				&nwip_universe, 208 },
	{ "option-209", "X",				&nwip_universe, 209 },
	{ "authenticate", "X",				&nwip_universe, 210 },
	{ "option-211", "X",				&nwip_universe, 211 },
	{ "option-212", "X",				&nwip_universe, 212 },
	{ "option-213", "X",				&nwip_universe, 213 },
	{ "option-214", "X",				&nwip_universe, 214 },
	{ "option-215", "X",				&nwip_universe, 215 },
	{ "option-216", "X",				&nwip_universe, 216 },
	{ "option-217", "X",				&nwip_universe, 217 },
	{ "option-218", "X",				&nwip_universe, 218 },
	{ "option-219", "X",				&nwip_universe, 219 },
	{ "option-220", "X",				&nwip_universe, 220 },
	{ "option-221", "X",				&nwip_universe, 221 },
	{ "option-222", "X",				&nwip_universe, 222 },
	{ "option-223", "X",				&nwip_universe, 223 },
	{ "option-224", "X",				&nwip_universe, 224 },
	{ "option-225", "X",				&nwip_universe, 225 },
	{ "option-226", "X",				&nwip_universe, 226 },
	{ "option-227", "X",				&nwip_universe, 227 },
	{ "option-228", "X",				&nwip_universe, 228 },
	{ "option-229", "X",				&nwip_universe, 229 },
	{ "option-230", "X",				&nwip_universe, 230 },
	{ "option-231", "X",				&nwip_universe, 231 },
	{ "option-232", "X",				&nwip_universe, 232 },
	{ "option-233", "X",				&nwip_universe, 233 },
	{ "option-234", "X",				&nwip_universe, 234 },
	{ "option-235", "X",				&nwip_universe, 235 },
	{ "option-236", "X",				&nwip_universe, 236 },
	{ "option-237", "X",				&nwip_universe, 237 },
	{ "option-238", "X",				&nwip_universe, 238 },
	{ "option-239", "X",				&nwip_universe, 239 },
	{ "option-240", "X",				&nwip_universe, 240 },
	{ "option-241", "X",				&nwip_universe, 241 },
	{ "option-242", "X",				&nwip_universe, 242 },
	{ "option-243", "X",				&nwip_universe, 243 },
	{ "option-244", "X",				&nwip_universe, 244 },
	{ "option-245", "X",				&nwip_universe, 245 },
	{ "option-246", "X",				&nwip_universe, 246 },
	{ "option-247", "X",				&nwip_universe, 247 },
	{ "option-248", "X",				&nwip_universe, 248 },
	{ "option-249", "X",				&nwip_universe, 249 },
	{ "option-250", "X",				&nwip_universe, 250 },
	{ "option-251", "X",				&nwip_universe, 251 },
	{ "option-252", "X",				&nwip_universe, 252 },
	{ "option-253", "X",				&nwip_universe, 253 },
	{ "option-254", "X",				&nwip_universe, 254 },
	{ "option-end", "e",				&nwip_universe, 255 },
};

const char *hardware_types [] = {
	"unknown-0",
	"ethernet",
	"unknown-2",
	"unknown-3",
	"unknown-4",
	"unknown-5",
	"token-ring",
	"unknown-7",
	"fddi",
	"unknown-9",
	"unknown-10",
	"unknown-11",
	"unknown-12",
	"unknown-13",
	"unknown-14",
	"unknown-15",
	"unknown-16",
	"unknown-17",
	"unknown-18",
	"unknown-19",
	"unknown-20",
	"unknown-21",
	"unknown-22",
	"unknown-23",
	"unknown-24",
	"unknown-25",
	"unknown-26",
	"unknown-27",
	"unknown-28",
	"unknown-29",
	"unknown-30",
	"unknown-31",
	"unknown-32",
	"unknown-33",
	"unknown-34",
	"unknown-35",
	"unknown-36",
	"unknown-37",
	"unknown-38",
	"unknown-39",
	"unknown-40",
	"unknown-41",
	"unknown-42",
	"unknown-43",
	"unknown-44",
	"unknown-45",
	"unknown-46",
	"unknown-47",
	"unknown-48",
	"unknown-49",
	"unknown-50",
	"unknown-51",
	"unknown-52",
	"unknown-53",
	"unknown-54",
	"unknown-55",
	"unknown-56",
	"unknown-57",
	"unknown-58",
	"unknown-59",
	"unknown-60",
	"unknown-61",
	"unknown-62",
	"unknown-63",
	"unknown-64",
	"unknown-65",
	"unknown-66",
	"unknown-67",
	"unknown-68",
	"unknown-69",
	"unknown-70",
	"unknown-71",
	"unknown-72",
	"unknown-73",
	"unknown-74",
	"unknown-75",
	"unknown-76",
	"unknown-77",
	"unknown-78",
	"unknown-79",
	"unknown-80",
	"unknown-81",
	"unknown-82",
	"unknown-83",
	"unknown-84",
	"unknown-85",
	"unknown-86",
	"unknown-87",
	"unknown-88",
	"unknown-89",
	"unknown-90",
	"unknown-91",
	"unknown-92",
	"unknown-93",
	"unknown-94",
	"unknown-95",
	"unknown-96",
	"unknown-97",
	"unknown-98",
	"unknown-99",
	"unknown-100",
	"unknown-101",
	"unknown-102",
	"unknown-103",
	"unknown-104",
	"unknown-105",
	"unknown-106",
	"unknown-107",
	"unknown-108",
	"unknown-109",
	"unknown-110",
	"unknown-111",
	"unknown-112",
	"unknown-113",
	"unknown-114",
	"unknown-115",
	"unknown-116",
	"unknown-117",
	"unknown-118",
	"unknown-119",
	"unknown-120",
	"unknown-121",
	"unknown-122",
	"unknown-123",
	"unknown-124",
	"unknown-125",
	"unknown-126",
	"unknown-127",
	"unknown-128",
	"unknown-129",
	"unknown-130",
	"unknown-131",
	"unknown-132",
	"unknown-133",
	"unknown-134",
	"unknown-135",
	"unknown-136",
	"unknown-137",
	"unknown-138",
	"unknown-139",
	"unknown-140",
	"unknown-141",
	"unknown-142",
	"unknown-143",
	"unknown-144",
	"unknown-145",
	"unknown-146",
	"unknown-147",
	"unknown-148",
	"unknown-149",
	"unknown-150",
	"unknown-151",
	"unknown-152",
	"unknown-153",
	"unknown-154",
	"unknown-155",
	"unknown-156",
	"unknown-157",
	"unknown-158",
	"unknown-159",
	"unknown-160",
	"unknown-161",
	"unknown-162",
	"unknown-163",
	"unknown-164",
	"unknown-165",
	"unknown-166",
	"unknown-167",
	"unknown-168",
	"unknown-169",
	"unknown-170",
	"unknown-171",
	"unknown-172",
	"unknown-173",
	"unknown-174",
	"unknown-175",
	"unknown-176",
	"unknown-177",
	"unknown-178",
	"unknown-179",
	"unknown-180",
	"unknown-181",
	"unknown-182",
	"unknown-183",
	"unknown-184",
	"unknown-185",
	"unknown-186",
	"unknown-187",
	"unknown-188",
	"unknown-189",
	"unknown-190",
	"unknown-191",
	"unknown-192",
	"unknown-193",
	"unknown-194",
	"unknown-195",
	"unknown-196",
	"unknown-197",
	"unknown-198",
	"unknown-199",
	"unknown-200",
	"unknown-201",
	"unknown-202",
	"unknown-203",
	"unknown-204",
	"unknown-205",
	"unknown-206",
	"unknown-207",
	"unknown-208",
	"unknown-209",
	"unknown-210",
	"unknown-211",
	"unknown-212",
	"unknown-213",
	"unknown-214",
	"unknown-215",
	"unknown-216",
	"unknown-217",
	"unknown-218",
	"unknown-219",
	"unknown-220",
	"unknown-221",
	"unknown-222",
	"unknown-223",
	"unknown-224",
	"unknown-225",
	"unknown-226",
	"unknown-227",
	"unknown-228",
	"unknown-229",
	"unknown-230",
	"unknown-231",
	"unknown-232",
	"unknown-233",
	"unknown-234",
	"unknown-235",
	"unknown-236",
	"unknown-237",
	"unknown-238",
	"unknown-239",
	"unknown-240",
	"unknown-241",
	"unknown-242",
	"unknown-243",
	"unknown-244",
	"unknown-245",
	"unknown-246",
	"unknown-247",
	"unknown-248",
	"unknown-249",
	"unknown-250",
	"unknown-251",
	"unknown-252",
	"unknown-253",
	"unknown-254",
	"unknown-255" };

struct hash_table universe_hash;
struct universe **universes;
int universe_count, universe_max;

void initialize_common_option_spaces()
{
	int i;

	universe_max = 10;
	universes = ((struct universe **)
		     dmalloc (universe_max * sizeof (struct universe *), MDL));
	if (!universes)
		log_fatal ("Can't allocate option space table.");
	memset (universes, 0, universe_max * sizeof (struct universe *));

	/* Set up the DHCP option universe... */
	dhcp_universe.name = "dhcp";
	dhcp_universe.lookup_func = lookup_hashed_option;
	dhcp_universe.option_state_dereference =
		hashed_option_state_dereference;
	dhcp_universe.get_func = hashed_option_get;
	dhcp_universe.set_func = hashed_option_set;
	dhcp_universe.save_func = save_hashed_option;
	dhcp_universe.delete_func = delete_hashed_option;
	dhcp_universe.encapsulate = hashed_option_space_encapsulate;
	dhcp_universe.length_size = 1;
	dhcp_universe.tag_size = 1;
	dhcp_universe.store_tag = putUChar;
	dhcp_universe.store_length = putUChar;
	dhcp_universe.index = universe_count++;
	universes [dhcp_universe.index] = &dhcp_universe;
	dhcp_universe.hash = new_hash ();
	if (!dhcp_universe.hash)
		log_fatal ("Can't allocate dhcp option hash table.");
	for (i = 0; i < 256; i++) {
		dhcp_universe.options [i] = &dhcp_options [i];
		add_hash (dhcp_universe.hash,
			  (const unsigned char *)dhcp_options [i].name, 0,
			  (unsigned char *)&dhcp_options [i]);
	}

	/* Set up the Novell option universe (for option 63)... */
	nwip_universe.name = "nwip";
	nwip_universe.lookup_func = lookup_hashed_option;
	nwip_universe.option_state_dereference =
		hashed_option_state_dereference;
	nwip_universe.get_func = hashed_option_get;
	nwip_universe.set_func = hashed_option_set;
	nwip_universe.save_func = save_hashed_option;
	nwip_universe.delete_func = delete_hashed_option;
	nwip_universe.encapsulate = nwip_option_space_encapsulate;
	nwip_universe.length_size = 1;
	nwip_universe.tag_size = 1;
	nwip_universe.store_tag = putUChar;
	nwip_universe.store_length = putUChar;
	nwip_universe.index = universe_count++;
	universes [nwip_universe.index] = &nwip_universe;
	nwip_universe.hash = new_hash ();
	if (!nwip_universe.hash)
		log_fatal ("Can't allocate dhcp option hash table.");
	for (i = 0; i < 256; i++) {
		nwip_universe.options [i] = &dhcp_options [i];
		add_hash (nwip_universe.hash,
			  (const unsigned char *)dhcp_options [i].name, 0,
			  (unsigned char *)&dhcp_options [i]);
	}

	/* Set up the hash of universes. */
	universe_hash.hash_count = DEFAULT_HASH_SIZE;	
	add_hash (&universe_hash,
		  (const unsigned char *)dhcp_universe.name, 0,
		  (unsigned char *)&dhcp_universe);
	add_hash (&universe_hash,
		  (const unsigned char *)nwip_universe.name, 0,
		  (unsigned char *)&nwip_universe);
}
