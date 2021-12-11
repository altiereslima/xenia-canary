#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 10.1
//
//
// Buffer Definitions: 
//
// cbuffer XeTextureLoadConstants
// {
//
//   uint xe_texture_load_is_tiled_3d_endian_scale;// Offset:    0 Size:     4
//   uint xe_texture_load_guest_offset; // Offset:    4 Size:     4
//   uint xe_texture_load_guest_pitch_aligned;// Offset:    8 Size:     4
//   uint xe_texture_load_guest_z_stride_block_rows_aligned;// Offset:   12 Size:     4
//   uint3 xe_texture_load_size_blocks; // Offset:   16 Size:    12
//   uint xe_texture_load_host_offset;  // Offset:   28 Size:     4
//   uint xe_texture_load_host_pitch;   // Offset:   32 Size:     4
//   uint xe_texture_load_height_texels;// Offset:   36 Size:     4 [unused]
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim      ID      HLSL Bind  Count
// ------------------------------ ---------- ------- ----------- ------- -------------- ------
// xe_texture_load_source            texture   uint4         buf      T0             t0      1 
// xe_texture_load_dest                  UAV   uint4         buf      U0             u0      1 
// XeTextureLoadConstants            cbuffer      NA          NA     CB0            cb0      1 
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Input
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Output
cs_5_1
dcl_globalFlags refactoringAllowed
dcl_constantbuffer CB0[0:0][3], immediateIndexed, space=0
dcl_resource_buffer (uint,uint,uint,uint) T0[0:0], space=0
dcl_uav_typed_buffer (uint,uint,uint,uint) U0[0:0], space=0
dcl_input vThreadID.xyz
dcl_temps 5
dcl_thread_group 2, 32, 1
ishl r0.x, vThreadID.x, l(4)
mov r0.yz, vThreadID.yyzy
uge r0.yzw, r0.xxyz, CB0[0][1].xxyz
or r0.y, r0.z, r0.y
or r0.y, r0.w, r0.y
if_nz r0.y
  ret 
endif 
ishl r0.y, r0.x, l(1)
imad r0.z, vThreadID.z, CB0[0][1].y, vThreadID.y
imad r0.z, r0.z, CB0[0][2].x, r0.y
iadd r0.z, r0.z, CB0[0][1].w
and r0.w, CB0[0][0].x, l(1)
if_nz r0.w
  and r1.x, CB0[0][0].x, l(2)
  if_nz r1.x
    ishr r1.xyz, vThreadID.yzyy, l(4, 2, 3, 0)
    ushr r2.xy, CB0[0][0].wzww, l(4, 5, 0, 0)
    imad r1.x, r1.y, r2.x, r1.x
    ibfe r1.w, l(27), l(1), vThreadID.x
    imad r1.x, r1.x, r2.y, r1.w
    ishl r1.w, vThreadID.y, l(9)
    ishr r1.w, r1.w, l(6)
    iadd r1.y, r1.y, r1.z
    and r1.zw, r1.yyyw, l(0, 0, 1, 48)
    ishr r2.x, r0.x, l(3)
    bfi r1.y, l(1), l(1), r1.y, l(0)
    iadd r1.y, r1.y, r2.x
    bfi r1.y, l(2), l(1), r1.y, l(0)
    iadd r1.y, r1.y, r1.z
    bfi r1.xz, l(21, 0, 21, 0), l(9, 0, 12, 0), r1.xxxx, l(0, 0, 0, 0)
    imad r1.xz, r1.wwww, l(2, 0, 16, 0), r1.xxzx
    bfi r1.xz, l(2, 0, 2, 0), l(7, 0, 10, 0), vThreadID.zzzz, r1.xxzx
    bfi r1.w, l(1), l(4), vThreadID.y, l(0)
    ubfe r2.x, l(3), l(6), r1.x
    and r2.y, r1.y, l(4)
    bfi r1.y, l(2), l(8), r1.y, l(0)
    imad r1.y, r2.x, l(32), r1.y
    imad r1.y, r2.y, l(4), r1.y
    bfi r1.xz, l(5, 0, 5, 0), l(0, 0, 3, 0), r1.wwww, r1.xxzx
    bfi r1.y, l(9), l(3), r1.y, r1.z
    bfi r1.x, l(6), l(0), r1.x, r1.y
  else 
    ibfe r1.y, l(27), l(1), vThreadID.x
    ishr r1.zw, vThreadID.yyyy, l(0, 0, 5, 2)
    ushr r2.x, CB0[0][0].z, l(5)
    imad r1.y, r1.z, r2.x, r1.y
    bfi r2.xyz, l(4, 4, 4, 0), l(4, 7, 6, 0), vThreadID.yyyy, l(0, 0, 0, 0)
    bfi r2.xyz, l(24, 24, 24, 0), l(8, 11, 10, 0), r1.yyyy, r2.xyzx
    ishl r1.y, vThreadID.y, l(7)
    and r1.y, r1.y, l(2048)
    bfi r1.y, l(12), l(0), r1.y, r2.y
    and r1.z, r2.z, l(1792)
    iadd r1.y, r1.y, r1.z
    and r1.z, r1.w, l(2)
    ishr r0.x, r0.x, l(3)
    iadd r0.x, r0.x, r1.z
    bfi r0.x, l(2), l(6), r0.x, l(0)
    iadd r0.x, r1.y, r0.x
    bfi r1.x, l(6), l(0), r2.x, r0.x
  endif 
else 
  imad r0.x, vThreadID.z, CB0[0][0].w, vThreadID.y
  imad r1.x, r0.x, CB0[0][0].z, r0.y
endif 
iadd r0.x, r1.x, CB0[0][0].y
ushr r0.xz, r0.xxzx, l(4, 0, 4, 0)
ubfe r0.y, l(2), l(2), CB0[0][0].x
ld r1.xyzw, r0.xxxx, T0[0].xyzw
ieq r0.y, r0.y, l(1)
if_nz r0.y
  ishl r2.xyzw, r1.xyzw, l(8, 8, 8, 8)
  and r2.xyzw, r2.xyzw, l(0xff00ff00, 0xff00ff00, 0xff00ff00, 0xff00ff00)
  ushr r3.xyzw, r1.xyzw, l(8, 8, 8, 8)
  and r3.xyzw, r3.xyzw, l(0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff)
  iadd r1.xyzw, r2.xyzw, r3.xyzw
endif 
and r2.xyzw, r1.xyzw, l(0xf0f0f0f0, 0xf0f0f0f0, 0xf0f0f0f0, 0xf0f0f0f0)
ishl r3.xyzw, r1.xyzw, l(8, 8, 8, 8)
and r3.xyzw, r3.xyzw, l(0x0f000f00, 0x0f000f00, 0x0f000f00, 0x0f000f00)
iadd r2.xyzw, r2.xyzw, r3.xyzw
ushr r1.xyzw, r1.xyzw, l(8, 8, 8, 8)
and r1.xyzw, r1.xyzw, l(0x000f000f, 0x000f000f, 0x000f000f, 0x000f000f)
iadd r1.xyzw, r1.xyzw, r2.xyzw
store_uav_typed U0[0].xyzw, r0.zzzz, r1.xyzw
iadd r1.x, r0.z, l(1)
if_nz r0.w
  mov r0.w, l(64)
else 
  mov r0.w, l(16)
endif 
ushr r0.w, r0.w, l(4)
iadd r0.x, r0.w, r0.x
ld r2.xyzw, r0.xxxx, T0[0].xyzw
if_nz r0.y
  ishl r3.xyzw, r2.xyzw, l(8, 8, 8, 8)
  and r3.xyzw, r3.xyzw, l(0xff00ff00, 0xff00ff00, 0xff00ff00, 0xff00ff00)
  ushr r4.xyzw, r2.xyzw, l(8, 8, 8, 8)
  and r4.xyzw, r4.xyzw, l(0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff)
  iadd r2.xyzw, r3.xyzw, r4.xyzw
endif 
and r3.xyzw, r2.xyzw, l(0xf0f0f0f0, 0xf0f0f0f0, 0xf0f0f0f0, 0xf0f0f0f0)
ishl r4.xyzw, r2.xyzw, l(8, 8, 8, 8)
and r4.xyzw, r4.xyzw, l(0x0f000f00, 0x0f000f00, 0x0f000f00, 0x0f000f00)
iadd r3.xyzw, r3.xyzw, r4.xyzw
ushr r2.xyzw, r2.xyzw, l(8, 8, 8, 8)
and r2.xyzw, r2.xyzw, l(0x000f000f, 0x000f000f, 0x000f000f, 0x000f000f)
iadd r2.xyzw, r2.xyzw, r3.xyzw
store_uav_typed U0[0].xyzw, r1.xxxx, r2.xyzw
ret 
// Approximately 110 instruction slots used
#endif

const BYTE texture_load_r4g4b4a4_b4g4r4a4_cs[] =
{
     68,  88,  66,  67, 123, 178, 
      4, 149, 160,  65, 196,  92, 
    197,  33, 231, 200, 130,  56, 
     69,  71,   1,   0,   0,   0, 
     28,  19,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
     28,   4,   0,   0,  44,   4, 
      0,   0,  60,   4,   0,   0, 
    128,  18,   0,   0,  82,  68, 
     69,  70, 224,   3,   0,   0, 
      1,   0,   0,   0, 248,   0, 
      0,   0,   3,   0,   0,   0, 
     60,   0,   0,   0,   1,   5, 
     83,  67,   0,   5,   4,   0, 
    181,   3,   0,   0,  19,  19, 
     68,  37,  60,   0,   0,   0, 
     24,   0,   0,   0,  40,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
    180,   0,   0,   0,   2,   0, 
      0,   0,   4,   0,   0,   0, 
      1,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
      1,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 203,   0, 
      0,   0,   4,   0,   0,   0, 
      4,   0,   0,   0,   1,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  12,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 224,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    120, 101,  95, 116, 101, 120, 
    116, 117, 114, 101,  95, 108, 
    111,  97, 100,  95, 115, 111, 
    117, 114,  99, 101,   0, 120, 
    101,  95, 116, 101, 120, 116, 
    117, 114, 101,  95, 108, 111, 
     97, 100,  95, 100, 101, 115, 
    116,   0,  88, 101,  84, 101, 
    120, 116, 117, 114, 101,  76, 
    111,  97, 100,  67, 111, 110, 
    115, 116,  97, 110, 116, 115, 
      0, 171, 224,   0,   0,   0, 
      8,   0,   0,   0,  16,   1, 
      0,   0,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  80,   2,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   2,   0,   0,   0, 
    128,   2,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    164,   2,   0,   0,   4,   0, 
      0,   0,   4,   0,   0,   0, 
      2,   0,   0,   0, 128,   2, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 193,   2, 
      0,   0,   8,   0,   0,   0, 
      4,   0,   0,   0,   2,   0, 
      0,   0, 128,   2,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 229,   2,   0,   0, 
     12,   0,   0,   0,   4,   0, 
      0,   0,   2,   0,   0,   0, 
    128,   2,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     23,   3,   0,   0,  16,   0, 
      0,   0,  12,   0,   0,   0, 
      2,   0,   0,   0,  60,   3, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  96,   3, 
      0,   0,  28,   0,   0,   0, 
      4,   0,   0,   0,   2,   0, 
      0,   0, 128,   2,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 124,   3,   0,   0, 
     32,   0,   0,   0,   4,   0, 
      0,   0,   2,   0,   0,   0, 
    128,   2,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    151,   3,   0,   0,  36,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0, 128,   2, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 120, 101, 
     95, 116, 101, 120, 116, 117, 
    114, 101,  95, 108, 111,  97, 
    100,  95, 105, 115,  95, 116, 
    105, 108, 101, 100,  95,  51, 
    100,  95, 101, 110, 100, 105, 
     97, 110,  95, 115,  99,  97, 
    108, 101,   0, 100, 119, 111, 
    114, 100,   0, 171,   0,   0, 
     19,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    121,   2,   0,   0, 120, 101, 
     95, 116, 101, 120, 116, 117, 
    114, 101,  95, 108, 111,  97, 
    100,  95, 103, 117, 101, 115, 
    116,  95, 111, 102, 102, 115, 
    101, 116,   0, 120, 101,  95, 
    116, 101, 120, 116, 117, 114, 
    101,  95, 108, 111,  97, 100, 
     95, 103, 117, 101, 115, 116, 
     95, 112, 105, 116,  99, 104, 
     95,  97, 108, 105, 103, 110, 
    101, 100,   0, 120, 101,  95, 
    116, 101, 120, 116, 117, 114, 
    101,  95, 108, 111,  97, 100, 
     95, 103, 117, 101, 115, 116, 
     95, 122,  95, 115, 116, 114, 
    105, 100, 101,  95,  98, 108, 
    111,  99, 107,  95, 114, 111, 
    119, 115,  95,  97, 108, 105, 
    103, 110, 101, 100,   0, 120, 
    101,  95, 116, 101, 120, 116, 
    117, 114, 101,  95, 108, 111, 
     97, 100,  95, 115, 105, 122, 
    101,  95,  98, 108, 111,  99, 
    107, 115,   0, 117, 105, 110, 
    116,  51,   0, 171, 171, 171, 
      1,   0,  19,   0,   1,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  51,   3,   0,   0, 
    120, 101,  95, 116, 101, 120, 
    116, 117, 114, 101,  95, 108, 
    111,  97, 100,  95, 104, 111, 
    115, 116,  95, 111, 102, 102, 
    115, 101, 116,   0, 120, 101, 
     95, 116, 101, 120, 116, 117, 
    114, 101,  95, 108, 111,  97, 
    100,  95, 104, 111, 115, 116, 
     95, 112, 105, 116,  99, 104, 
      0, 120, 101,  95, 116, 101, 
    120, 116, 117, 114, 101,  95, 
    108, 111,  97, 100,  95, 104, 
    101, 105, 103, 104, 116,  95, 
    116, 101, 120, 101, 108, 115, 
      0,  77, 105,  99, 114, 111, 
    115, 111, 102, 116,  32,  40, 
     82,  41,  32,  72,  76,  83, 
     76,  32,  83, 104,  97, 100, 
    101, 114,  32,  67, 111, 109, 
    112, 105, 108, 101, 114,  32, 
     49,  48,  46,  49,   0, 171, 
    171, 171,  73,  83,  71,  78, 
      8,   0,   0,   0,   0,   0, 
      0,   0,   8,   0,   0,   0, 
     79,  83,  71,  78,   8,   0, 
      0,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,  83,  72, 
     69,  88,  60,  14,   0,   0, 
     81,   0,   5,   0, 143,   3, 
      0,   0, 106,   8,   0,   1, 
     89,   0,   0,   7,  70, 142, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  88,   8, 
      0,   7,  70, 126,  48,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     68,  68,   0,   0,   0,   0, 
      0,   0, 156,   8,   0,   7, 
     70, 238,  49,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  68,  68, 
      0,   0,   0,   0,   0,   0, 
     95,   0,   0,   2, 114,   0, 
      2,   0, 104,   0,   0,   2, 
      5,   0,   0,   0, 155,   0, 
      0,   4,   2,   0,   0,   0, 
     32,   0,   0,   0,   1,   0, 
      0,   0,  41,   0,   0,   6, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,   2,   0, 
      1,  64,   0,   0,   4,   0, 
      0,   0,  54,   0,   0,   4, 
     98,   0,  16,   0,   0,   0, 
      0,   0,  86,   6,   2,   0, 
     80,   0,   0,   9, 226,   0, 
     16,   0,   0,   0,   0,   0, 
      6,   9,  16,   0,   0,   0, 
      0,   0,   6, 137,  48,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     60,   0,   0,   7,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  60,   0, 
      0,   7,  34,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  31,   0,   4,   3, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  62,   0,   0,   1, 
     21,   0,   0,   1,  41,   0, 
      0,   7,  34,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   1,   0, 
      0,   0,  35,   0,   0,   9, 
     66,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,   2,   0, 
     26, 128,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  26,   0, 
      2,   0,  35,   0,   0,  11, 
     66,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,  10, 128, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  30,   0, 
      0,   9,  66,   0,  16,   0, 
      0,   0,   0,   0,  42,   0, 
     16,   0,   0,   0,   0,   0, 
     58, 128,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   9, 130,   0,  16,   0, 
      0,   0,   0,   0,  10, 128, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      1,   0,   0,   0,  31,   0, 
      4,   3,  58,   0,  16,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   9,  18,   0,  16,   0, 
      1,   0,   0,   0,  10, 128, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      2,   0,   0,   0,  31,   0, 
      4,   3,  10,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
      0,   9, 114,   0,  16,   0, 
      1,   0,   0,   0, 150,   5, 
      2,   0,   2,  64,   0,   0, 
      4,   0,   0,   0,   2,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  85,   0, 
      0,  12,  50,   0,  16,   0, 
      2,   0,   0,   0, 182, 143, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      4,   0,   0,   0,   5,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  35,   0, 
      0,   9,  18,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0, 139,   0, 
      0,   8, 130,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,  27,   0,   0,   0, 
      1,  64,   0,   0,   1,   0, 
      0,   0,  10,   0,   2,   0, 
     35,   0,   0,   9,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      2,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     41,   0,   0,   6, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,   2,   0,   1,  64, 
      0,   0,   9,   0,   0,   0, 
     42,   0,   0,   7, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      6,   0,   0,   0,  30,   0, 
      0,   7,  34,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,   1,   0,   0,  10, 
    194,   0,  16,   0,   1,   0, 
      0,   0,  86,  13,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  48,   0,   0,   0, 
     42,   0,   0,   7,  18,   0, 
     16,   0,   2,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      3,   0,   0,   0, 140,   0, 
      0,  11,  34,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     30,   0,   0,   7,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      2,   0,   0,   0, 140,   0, 
      0,  11,  34,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   2,   0,   0,   0, 
      1,  64,   0,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     30,   0,   0,   7,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0, 140,   0, 
      0,  20,  82,   0,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,  21,   0,   0,   0, 
      0,   0,   0,   0,  21,   0, 
      0,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   9,   0, 
      0,   0,   0,   0,   0,   0, 
     12,   0,   0,   0,   0,   0, 
      0,   0,   6,   0,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     35,   0,   0,  12,  82,   0, 
     16,   0,   1,   0,   0,   0, 
    246,  15,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,  16,   0,   0,   0, 
      0,   0,   0,   0,   6,   2, 
     16,   0,   1,   0,   0,   0, 
    140,   0,   0,  16,  82,   0, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      7,   0,   0,   0,   0,   0, 
      0,   0,  10,   0,   0,   0, 
      0,   0,   0,   0, 166,  10, 
      2,   0,   6,   2,  16,   0, 
      1,   0,   0,   0, 140,   0, 
      0,  10, 130,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   4,   0, 
      0,   0,  26,   0,   2,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0, 138,   0,   0,   9, 
     18,   0,  16,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      3,   0,   0,   0,   1,  64, 
      0,   0,   6,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,   1,   0,   0,   7, 
     34,   0,  16,   0,   2,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   4,   0,   0,   0, 
    140,   0,   0,  11,  34,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      8,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  35,   0,   0,   9, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      2,   0,   0,   0,   1,  64, 
      0,   0,  32,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  35,   0,   0,   9, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      2,   0,   0,   0,   1,  64, 
      0,   0,   4,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0, 140,   0,   0,  17, 
     82,   0,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      5,   0,   0,   0,   0,   0, 
      0,   0,   5,   0,   0,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
    246,  15,  16,   0,   1,   0, 
      0,   0,   6,   2,  16,   0, 
      1,   0,   0,   0, 140,   0, 
      0,  11,  34,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   9,   0,   0,   0, 
      1,  64,   0,   0,   3,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
    140,   0,   0,  11,  18,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   6,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  18,   0,   0,   1, 
    139,   0,   0,   8,  34,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,  27,   0, 
      0,   0,   1,  64,   0,   0, 
      1,   0,   0,   0,  10,   0, 
      2,   0,  42,   0,   0,   9, 
    194,   0,  16,   0,   1,   0, 
      0,   0,  86,   5,   2,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      5,   0,   0,   0,   2,   0, 
      0,   0,  85,   0,   0,   9, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  42, 128,  48,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   5,   0, 
      0,   0,  35,   0,   0,   9, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0, 140,   0,   0,  19, 
    114,   0,  16,   0,   2,   0, 
      0,   0,   2,  64,   0,   0, 
      4,   0,   0,   0,   4,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   4,   0,   0,   0, 
      7,   0,   0,   0,   6,   0, 
      0,   0,   0,   0,   0,   0, 
     86,   5,   2,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    140,   0,   0,  17, 114,   0, 
     16,   0,   2,   0,   0,   0, 
      2,  64,   0,   0,  24,   0, 
      0,   0,  24,   0,   0,   0, 
     24,   0,   0,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      8,   0,   0,   0,  11,   0, 
      0,   0,  10,   0,   0,   0, 
      0,   0,   0,   0,  86,   5, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  41,   0,   0,   6, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,   2,   0, 
      1,  64,   0,   0,   7,   0, 
      0,   0,   1,   0,   0,   7, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   8,   0,   0, 
    140,   0,   0,  11,  34,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,  12,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   2,   0, 
      0,   0,   1,   0,   0,   7, 
     66,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      2,   0,   0,   0,   1,  64, 
      0,   0,   0,   7,   0,   0, 
     30,   0,   0,   7,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   7,  66,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   2,   0, 
      0,   0,  42,   0,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   3,   0,   0,   0, 
     30,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0, 140,   0, 
      0,  11,  18,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   2,   0,   0,   0, 
      1,  64,   0,   0,   6,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     30,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0, 140,   0, 
      0,  11,  18,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   6,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     21,   0,   0,   1,  18,   0, 
      0,   1,  35,   0,   0,   9, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,   2,   0, 
     58, 128,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  26,   0, 
      2,   0,  35,   0,   0,  11, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  42, 128, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  21,   0, 
      0,   1,  30,   0,   0,   9, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  26, 128, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  85,   0,   0,  10, 
     82,   0,  16,   0,   0,   0, 
      0,   0,   6,   2,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
    138,   0,   0,  11,  34,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      2,   0,   0,   0,  10, 128, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  45,   0,   0,   8, 
    242,   0,  16,   0,   1,   0, 
      0,   0,   6,   0,  16,   0, 
      0,   0,   0,   0,  70, 126, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  32,   0, 
      0,   7,  34,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   1,   0, 
      0,   0,  31,   0,   4,   3, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  41,   0,   0,  10, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   8,   0,   0,   0, 
      8,   0,   0,   0,   8,   0, 
      0,   0,   8,   0,   0,   0, 
      1,   0,   0,  10, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,   2,  64,   0,   0, 
      0, 255,   0, 255,   0, 255, 
      0, 255,   0, 255,   0, 255, 
      0, 255,   0, 255,  85,   0, 
      0,  10, 242,   0,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   8,   0, 
      0,   0,   8,   0,   0,   0, 
      8,   0,   0,   0,   8,   0, 
      0,   0,   1,   0,   0,  10, 
    242,   0,  16,   0,   3,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,   2,  64, 
      0,   0, 255,   0, 255,   0, 
    255,   0, 255,   0, 255,   0, 
    255,   0, 255,   0, 255,   0, 
     30,   0,   0,   7, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,  21,   0, 
      0,   1,   1,   0,   0,  10, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0, 240, 240, 240, 240, 
    240, 240, 240, 240, 240, 240, 
    240, 240, 240, 240, 240, 240, 
     41,   0,   0,  10, 242,   0, 
     16,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      8,   0,   0,   0,   8,   0, 
      0,   0,   8,   0,   0,   0, 
      8,   0,   0,   0,   1,   0, 
      0,  10, 242,   0,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
      2,  64,   0,   0,   0,  15, 
      0,  15,   0,  15,   0,  15, 
      0,  15,   0,  15,   0,  15, 
      0,  15,  30,   0,   0,   7, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
     85,   0,   0,  10, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      8,   0,   0,   0,   8,   0, 
      0,   0,   8,   0,   0,   0, 
      8,   0,   0,   0,   1,   0, 
      0,  10, 242,   0,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,  15,   0, 
     15,   0,  15,   0,  15,   0, 
     15,   0,  15,   0,  15,   0, 
     15,   0,  30,   0,   0,   7, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
    164,   0,   0,   8, 242, 224, 
     33,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 166,  10, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  30,   0,   0,   7, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   1,   0,   0,   0, 
     31,   0,   4,   3,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     54,   0,   0,   5, 130,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,  64,   0, 
      0,   0,  18,   0,   0,   1, 
     54,   0,   0,   5, 130,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,  16,   0, 
      0,   0,  21,   0,   0,   1, 
     85,   0,   0,   7, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      4,   0,   0,   0,  30,   0, 
      0,   7,  18,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  45,   0,   0,   8, 
    242,   0,  16,   0,   2,   0, 
      0,   0,   6,   0,  16,   0, 
      0,   0,   0,   0,  70, 126, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  31,   0, 
      4,   3,  26,   0,  16,   0, 
      0,   0,   0,   0,  41,   0, 
      0,  10, 242,   0,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
      2,  64,   0,   0,   8,   0, 
      0,   0,   8,   0,   0,   0, 
      8,   0,   0,   0,   8,   0, 
      0,   0,   1,   0,   0,  10, 
    242,   0,  16,   0,   3,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,   2,  64, 
      0,   0,   0, 255,   0, 255, 
      0, 255,   0, 255,   0, 255, 
      0, 255,   0, 255,   0, 255, 
     85,   0,   0,  10, 242,   0, 
     16,   0,   4,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,   2,  64,   0,   0, 
      8,   0,   0,   0,   8,   0, 
      0,   0,   8,   0,   0,   0, 
      8,   0,   0,   0,   1,   0, 
      0,  10, 242,   0,  16,   0, 
      4,   0,   0,   0,  70,  14, 
     16,   0,   4,   0,   0,   0, 
      2,  64,   0,   0, 255,   0, 
    255,   0, 255,   0, 255,   0, 
    255,   0, 255,   0, 255,   0, 
    255,   0,  30,   0,   0,   7, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   4,   0,   0,   0, 
     21,   0,   0,   1,   1,   0, 
      0,  10, 242,   0,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
      2,  64,   0,   0, 240, 240, 
    240, 240, 240, 240, 240, 240, 
    240, 240, 240, 240, 240, 240, 
    240, 240,  41,   0,   0,  10, 
    242,   0,  16,   0,   4,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,   2,  64, 
      0,   0,   8,   0,   0,   0, 
      8,   0,   0,   0,   8,   0, 
      0,   0,   8,   0,   0,   0, 
      1,   0,   0,  10, 242,   0, 
     16,   0,   4,   0,   0,   0, 
     70,  14,  16,   0,   4,   0, 
      0,   0,   2,  64,   0,   0, 
      0,  15,   0,  15,   0,  15, 
      0,  15,   0,  15,   0,  15, 
      0,  15,   0,  15,  30,   0, 
      0,   7, 242,   0,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   4,   0, 
      0,   0,  85,   0,   0,  10, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,   2,  64, 
      0,   0,   8,   0,   0,   0, 
      8,   0,   0,   0,   8,   0, 
      0,   0,   8,   0,   0,   0, 
      1,   0,   0,  10, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,   2,  64,   0,   0, 
     15,   0,  15,   0,  15,   0, 
     15,   0,  15,   0,  15,   0, 
     15,   0,  15,   0,  30,   0, 
      0,   7, 242,   0,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0, 164,   0,   0,   8, 
    242, 224,  33,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  62,   0, 
      0,   1,  83,  84,  65,  84, 
    148,   0,   0,   0, 110,   0, 
      0,   0,   5,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     40,   0,   0,   0,  28,   0, 
      0,   0,   5,   0,   0,   0, 
      6,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0
};
