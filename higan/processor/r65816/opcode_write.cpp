auto R65816::op_write_addr_b(reg16& reg) {
  aa.l = readPC();
  aa.h = readPC();
L writeDB(aa.w, reg);
}

auto R65816::op_write_addr_w(reg16& reg) {
  aa.l = readPC();
  aa.h = readPC();
  writeDB(aa.w + 0, reg >> 0);
L writeDB(aa.w + 1, reg >> 8);
}

auto R65816::op_write_addrr_b(reg16& reg, reg16& idx) {
  aa.l = readPC();
  aa.h = readPC();
  io();
L writeDB(aa.w + idx, reg);
}

auto R65816::op_write_addrr_w(reg16& reg, reg16& idx) {
  aa.l = readPC();
  aa.h = readPC();
  io();
  writeDB(aa.w + idx + 0, reg >> 0);
L writeDB(aa.w + idx + 1, reg >> 8);
}

auto R65816::op_write_longr_b(reg16& idx) {
  aa.l = readPC();
  aa.h = readPC();
  aa.b = readPC();
L writeLong(aa.d + idx, r.a.l);
}

auto R65816::op_write_longr_w(reg16& idx) {
  aa.l = readPC();
  aa.h = readPC();
  aa.b = readPC();
  writeLong(aa.d + idx + 0, r.a.l);
L writeLong(aa.d + idx + 1, r.a.h);
}

auto R65816::op_write_dp_b(reg16& reg) {
  dp = readPC();
  io2();
L writeDP(dp, reg);
}

auto R65816::op_write_dp_w(reg16& reg) {
  dp = readPC();
  io2();
  writeDP(dp + 0, reg >> 0);
L writeDP(dp + 1, reg >> 8);
}

auto R65816::op_write_dpr_b(reg16& reg, reg16& idx) {
  dp = readPC();
  io2();
  io();
L writeDP(dp + idx, reg);
}

auto R65816::op_write_dpr_w(reg16& reg, reg16& idx) {
  dp = readPC();
  io2();
  io();
  writeDP(dp + idx + 0, reg >> 0);
L writeDP(dp + idx + 1, reg >> 8);
}

auto R65816::op_sta_idp_b() {
  dp = readPC();
  io2();
  aa.l = readDP(dp + 0);
  aa.h = readDP(dp + 1);
L writeDB(aa.w, r.a.l);
}

auto R65816::op_sta_idp_w() {
  dp = readPC();
  io2();
  aa.l = readDP(dp + 0);
  aa.h = readDP(dp + 1);
  writeDB(aa.w + 0, r.a.l);
L writeDB(aa.w + 1, r.a.h);
}

auto R65816::op_sta_ildp_b() {
  dp = readPC();
  io2();
  aa.l = readDPn(dp + 0);
  aa.h = readDPn(dp + 1);
  aa.b = readDPn(dp + 2);
L writeLong(aa.d, r.a.l);
}

auto R65816::op_sta_ildp_w() {
  dp = readPC();
  io2();
  aa.l = readDPn(dp + 0);
  aa.h = readDPn(dp + 1);
  aa.b = readDPn(dp + 2);
  writeLong(aa.d + 0, r.a.l);
L writeLong(aa.d + 1, r.a.h);
}

auto R65816::op_sta_idpx_b() {
  dp = readPC();
  io2();
  io();
  aa.l = readDP(dp + r.x.w + 0);
  aa.h = readDP(dp + r.x.w + 1);
L writeDB(aa.w, r.a.l);
}

auto R65816::op_sta_idpx_w() {
  dp = readPC();
  io2();
  io();
  aa.l = readDP(dp + r.x.w + 0);
  aa.h = readDP(dp + r.x.w + 1);
  writeDB(aa.w + 0, r.a.l);
L writeDB(aa.w + 1, r.a.h);
}

auto R65816::op_sta_idpy_b() {
  dp = readPC();
  io2();
  aa.l = readDP(dp + 0);
  aa.h = readDP(dp + 1);
  io();
L writeDB(aa.w + r.y.w, r.a.l);
}

auto R65816::op_sta_idpy_w() {
  dp = readPC();
  io2();
  aa.l = readDP(dp + 0);
  aa.h = readDP(dp + 1);
  io();
  writeDB(aa.w + r.y.w + 0, r.a.l);
L writeDB(aa.w + r.y.w + 1, r.a.h);
}

auto R65816::op_sta_ildpy_b() {
  dp = readPC();
  io2();
  aa.l = readDPn(dp + 0);
  aa.h = readDPn(dp + 1);
  aa.b = readDPn(dp + 2);
L writeLong(aa.d + r.y.w, r.a.l);
}

auto R65816::op_sta_ildpy_w() {
  dp = readPC();
  io2();
  aa.l = readDPn(dp + 0);
  aa.h = readDPn(dp + 1);
  aa.b = readDPn(dp + 2);
  writeLong(aa.d + r.y.w + 0, r.a.l);
L writeLong(aa.d + r.y.w + 1, r.a.h);
}

auto R65816::op_sta_sr_b() {
  sp = readPC();
  io();
L writeSP(sp, r.a.l);
}

auto R65816::op_sta_sr_w() {
  sp = readPC();
  io();
  writeSP(sp + 0, r.a.l);
L writeSP(sp + 1, r.a.h);
}

auto R65816::op_sta_isry_b() {
  sp = readPC();
  io();
  aa.l = readSP(sp + 0);
  aa.h = readSP(sp + 1);
  io();
L writeDB(aa.w + r.y.w, r.a.l);
}

auto R65816::op_sta_isry_w() {
  sp = readPC();
  io();
  aa.l = readSP(sp + 0);
  aa.h = readSP(sp + 1);
  io();
  writeDB(aa.w + r.y.w + 0, r.a.l);
L writeDB(aa.w + r.y.w + 1, r.a.h);
}
