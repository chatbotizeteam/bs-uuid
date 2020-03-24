/* 16 byte array */
type bytesT = (
  int,
  int,
  int,
  int,
  int,
  int,
  int,
  int,
  int,
  int,
  int,
  int,
  int,
  int,
  int,
  int,
);

module V1 = {
  type t;
  type optionsT;
  [@bs.send] external toString: t => string = "toString";
  [@bs.obj]
  external options:
    (
      ~node: (int, int, int, int, int, int)=?,
      ~clockseq: int=?,
      ~msecs: int=?,
      ~nsecs: int=?,
      unit
    ) =>
    optionsT;
  [@bs.module "uuid"] external create: unit => t = "v1";
  [@bs.module "uuid"]
  external createWithOptions: (~options: optionsT) => t = "v1";
  [@bs.module "uuid"]
  external createWithBuffer:
    (~options: optionsT=?, ~buffer: array(int), ~offset: int, unit) => t =
    "v1";
};

module V3 = {
  type t;
  [@bs.send] external toString: t => string = "toString";
  [@bs.val] [@bs.module "uuid"] [@bs.scope "v3"] external _DNS: string = "DNS";
  [@bs.val] [@bs.module "uuid"] [@bs.scope "v3"] external _URL: string = "URL";
  [@bs.module "uuid"]
  external create:
    (
      ~name: string,
      ~namespace: [@bs.unwrap] [ | `Uuid(string) | `Bytes(bytesT)]
    ) =>
    t =
    "v3";
  [@bs.module "uuid"]
  external createWithBuffer:
    (
      ~name: string,
      ~namespace: [@bs.unwrap] [ | `Uuid(string) | `Bytes(bytesT)],
      ~buffer: array(int),
      ~offset: int=?,
      unit
    ) =>
    t =
    "v3";
};

module V4 = {
  type t;
  type optionsT;
  [@bs.send] external toString: t => string = "toString";
  [@bs.obj]
  external options:
    (~random: bytesT=?, ~rng: unit => bytesT=?, unit) => optionsT;
  [@bs.module "uuid"] external create: unit => t = "v4";
  [@bs.module "uuid"]
  external createWithOptions: (~options: optionsT) => t = "v4";
  [@bs.module "uuid"]
  external createWithBuffer:
    (~options: optionsT=?, ~buffer: array(int), ~offset: int=?, unit) => t =
    "v4";
};

module V5 = {
  type t;
  [@bs.send] external toString: t => string = "toString";
  [@bs.val] [@bs.module "uuid"] [@bs.scope "v5"] external _DNS: string = "DNS";
  [@bs.val] [@bs.module "uuid"] [@bs.scope "v5"] external _URL: string = "URL";
  [@bs.module "uuid"]
  external create:
    (
      ~name: string,
      ~namespace: [@bs.unwrap] [ | `Uuid(string) | `Bytes(bytesT)]
    ) =>
    t =
    "v5";
  [@bs.module "uuid"]
  external createWithBuffer:
    (
      ~name: string,
      ~namespace: [@bs.unwrap] [ | `Uuid(string) | `Bytes(bytesT)],
      ~buffer: array(int),
      ~offset: int=?,
      unit
    ) =>
    t =
    "v5";
};
