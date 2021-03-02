// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: PointCloud2.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "PointCloud2.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace ag {
namespace ros {

namespace {

const ::google::protobuf::Descriptor* PointCloud2_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PointCloud2_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_PointCloud2_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_PointCloud2_2eproto() {
  protobuf_AddDesc_PointCloud2_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "PointCloud2.proto");
  GOOGLE_CHECK(file != NULL);
  PointCloud2_descriptor_ = file->message_type(0);
  static const int PointCloud2_offsets_[9] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PointCloud2, header_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PointCloud2, height_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PointCloud2, width_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PointCloud2, fields_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PointCloud2, is_bigendian_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PointCloud2, point_step_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PointCloud2, row_step_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PointCloud2, data_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PointCloud2, is_dense_),
  };
  PointCloud2_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      PointCloud2_descriptor_,
      PointCloud2::default_instance_,
      PointCloud2_offsets_,
      -1,
      -1,
      -1,
      sizeof(PointCloud2),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PointCloud2, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PointCloud2, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_PointCloud2_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      PointCloud2_descriptor_, &PointCloud2::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_PointCloud2_2eproto() {
  delete PointCloud2::default_instance_;
  delete PointCloud2_reflection_;
}

void protobuf_AddDesc_PointCloud2_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_PointCloud2_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::ag::ros::protobuf_AddDesc_PointField_2eproto();
  ::ag::ros::protobuf_AddDesc_Header_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\021PointCloud2.proto\022\006ag.ros\032\020PointField."
    "proto\032\014Header.proto\"\314\001\n\013PointCloud2\022\036\n\006h"
    "eader\030\001 \001(\0132\016.ag.ros.Header\022\016\n\006height\030\002 "
    "\001(\r\022\r\n\005width\030\003 \001(\r\022\"\n\006fields\030\004 \003(\0132\022.ag."
    "ros.PointField\022\024\n\014is_bigendian\030\005 \001(\010\022\022\n\n"
    "point_step\030\006 \001(\r\022\020\n\010row_step\030\007 \001(\r\022\014\n\004da"
    "ta\030\010 \001(\014\022\020\n\010is_dense\030\t \001(\010b\006proto3", 274);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "PointCloud2.proto", &protobuf_RegisterTypes);
  PointCloud2::default_instance_ = new PointCloud2();
  PointCloud2::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_PointCloud2_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_PointCloud2_2eproto {
  StaticDescriptorInitializer_PointCloud2_2eproto() {
    protobuf_AddDesc_PointCloud2_2eproto();
  }
} static_descriptor_initializer_PointCloud2_2eproto_;

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int PointCloud2::kHeaderFieldNumber;
const int PointCloud2::kHeightFieldNumber;
const int PointCloud2::kWidthFieldNumber;
const int PointCloud2::kFieldsFieldNumber;
const int PointCloud2::kIsBigendianFieldNumber;
const int PointCloud2::kPointStepFieldNumber;
const int PointCloud2::kRowStepFieldNumber;
const int PointCloud2::kDataFieldNumber;
const int PointCloud2::kIsDenseFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

PointCloud2::PointCloud2()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:ag.ros.PointCloud2)
}

void PointCloud2::InitAsDefaultInstance() {
  _is_default_instance_ = true;
  header_ = const_cast< ::ag::ros::Header*>(&::ag::ros::Header::default_instance());
}

PointCloud2::PointCloud2(const PointCloud2& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:ag.ros.PointCloud2)
}

void PointCloud2::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  header_ = NULL;
  height_ = 0u;
  width_ = 0u;
  is_bigendian_ = false;
  point_step_ = 0u;
  row_step_ = 0u;
  data_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  is_dense_ = false;
}

PointCloud2::~PointCloud2() {
  // @@protoc_insertion_point(destructor:ag.ros.PointCloud2)
  SharedDtor();
}

void PointCloud2::SharedDtor() {
  data_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
    delete header_;
  }
}

void PointCloud2::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PointCloud2::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PointCloud2_descriptor_;
}

const PointCloud2& PointCloud2::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_PointCloud2_2eproto();
  return *default_instance_;
}

PointCloud2* PointCloud2::default_instance_ = NULL;

PointCloud2* PointCloud2::New(::google::protobuf::Arena* arena) const {
  PointCloud2* n = new PointCloud2;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void PointCloud2::Clear() {
// @@protoc_insertion_point(message_clear_start:ag.ros.PointCloud2)
#if defined(__clang__)
#define ZR_HELPER_(f) \
  _Pragma("clang diagnostic push") \
  _Pragma("clang diagnostic ignored \"-Winvalid-offsetof\"") \
  __builtin_offsetof(PointCloud2, f) \
  _Pragma("clang diagnostic pop")
#else
#define ZR_HELPER_(f) reinterpret_cast<char*>(\
  &reinterpret_cast<PointCloud2*>(16)->f)
#endif

#define ZR_(first, last) do {\
  ::memset(&first, 0,\
           ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last));\
} while (0)

  ZR_(height_, width_);
  ZR_(point_step_, row_step_);
  if (GetArenaNoVirtual() == NULL && header_ != NULL) delete header_;
  header_ = NULL;
  is_bigendian_ = false;
  data_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  is_dense_ = false;

#undef ZR_HELPER_
#undef ZR_

  fields_.Clear();
}

bool PointCloud2::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:ag.ros.PointCloud2)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .ag.ros.Header header = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_header()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_height;
        break;
      }

      // optional uint32 height = 2;
      case 2: {
        if (tag == 16) {
         parse_height:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &height_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_width;
        break;
      }

      // optional uint32 width = 3;
      case 3: {
        if (tag == 24) {
         parse_width:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &width_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_fields;
        break;
      }

      // repeated .ag.ros.PointField fields = 4;
      case 4: {
        if (tag == 34) {
         parse_fields:
          DO_(input->IncrementRecursionDepth());
         parse_loop_fields:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_fields()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_loop_fields;
        input->UnsafeDecrementRecursionDepth();
        if (input->ExpectTag(40)) goto parse_is_bigendian;
        break;
      }

      // optional bool is_bigendian = 5;
      case 5: {
        if (tag == 40) {
         parse_is_bigendian:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_bigendian_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_point_step;
        break;
      }

      // optional uint32 point_step = 6;
      case 6: {
        if (tag == 48) {
         parse_point_step:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &point_step_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_row_step;
        break;
      }

      // optional uint32 row_step = 7;
      case 7: {
        if (tag == 56) {
         parse_row_step:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &row_step_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(66)) goto parse_data;
        break;
      }

      // optional bytes data = 8;
      case 8: {
        if (tag == 66) {
         parse_data:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_data()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(72)) goto parse_is_dense;
        break;
      }

      // optional bool is_dense = 9;
      case 9: {
        if (tag == 72) {
         parse_is_dense:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_dense_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:ag.ros.PointCloud2)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:ag.ros.PointCloud2)
  return false;
#undef DO_
}

void PointCloud2::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:ag.ros.PointCloud2)
  // optional .ag.ros.Header header = 1;
  if (this->has_header()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, *this->header_, output);
  }

  // optional uint32 height = 2;
  if (this->height() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->height(), output);
  }

  // optional uint32 width = 3;
  if (this->width() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->width(), output);
  }

  // repeated .ag.ros.PointField fields = 4;
  for (unsigned int i = 0, n = this->fields_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->fields(i), output);
  }

  // optional bool is_bigendian = 5;
  if (this->is_bigendian() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(5, this->is_bigendian(), output);
  }

  // optional uint32 point_step = 6;
  if (this->point_step() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(6, this->point_step(), output);
  }

  // optional uint32 row_step = 7;
  if (this->row_step() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(7, this->row_step(), output);
  }

  // optional bytes data = 8;
  if (this->data().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      8, this->data(), output);
  }

  // optional bool is_dense = 9;
  if (this->is_dense() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(9, this->is_dense(), output);
  }

  // @@protoc_insertion_point(serialize_end:ag.ros.PointCloud2)
}

::google::protobuf::uint8* PointCloud2::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:ag.ros.PointCloud2)
  // optional .ag.ros.Header header = 1;
  if (this->has_header()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        1, *this->header_, false, target);
  }

  // optional uint32 height = 2;
  if (this->height() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->height(), target);
  }

  // optional uint32 width = 3;
  if (this->width() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->width(), target);
  }

  // repeated .ag.ros.PointField fields = 4;
  for (unsigned int i = 0, n = this->fields_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        4, this->fields(i), false, target);
  }

  // optional bool is_bigendian = 5;
  if (this->is_bigendian() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(5, this->is_bigendian(), target);
  }

  // optional uint32 point_step = 6;
  if (this->point_step() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(6, this->point_step(), target);
  }

  // optional uint32 row_step = 7;
  if (this->row_step() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(7, this->row_step(), target);
  }

  // optional bytes data = 8;
  if (this->data().size() > 0) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        8, this->data(), target);
  }

  // optional bool is_dense = 9;
  if (this->is_dense() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(9, this->is_dense(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:ag.ros.PointCloud2)
  return target;
}

int PointCloud2::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:ag.ros.PointCloud2)
  int total_size = 0;

  // optional .ag.ros.Header header = 1;
  if (this->has_header()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->header_);
  }

  // optional uint32 height = 2;
  if (this->height() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->height());
  }

  // optional uint32 width = 3;
  if (this->width() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->width());
  }

  // optional bool is_bigendian = 5;
  if (this->is_bigendian() != 0) {
    total_size += 1 + 1;
  }

  // optional uint32 point_step = 6;
  if (this->point_step() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->point_step());
  }

  // optional uint32 row_step = 7;
  if (this->row_step() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->row_step());
  }

  // optional bytes data = 8;
  if (this->data().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->data());
  }

  // optional bool is_dense = 9;
  if (this->is_dense() != 0) {
    total_size += 1 + 1;
  }

  // repeated .ag.ros.PointField fields = 4;
  total_size += 1 * this->fields_size();
  for (int i = 0; i < this->fields_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->fields(i));
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PointCloud2::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ag.ros.PointCloud2)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const PointCloud2* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const PointCloud2>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ag.ros.PointCloud2)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ag.ros.PointCloud2)
    MergeFrom(*source);
  }
}

void PointCloud2::MergeFrom(const PointCloud2& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ag.ros.PointCloud2)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  fields_.MergeFrom(from.fields_);
  if (from.has_header()) {
    mutable_header()->::ag::ros::Header::MergeFrom(from.header());
  }
  if (from.height() != 0) {
    set_height(from.height());
  }
  if (from.width() != 0) {
    set_width(from.width());
  }
  if (from.is_bigendian() != 0) {
    set_is_bigendian(from.is_bigendian());
  }
  if (from.point_step() != 0) {
    set_point_step(from.point_step());
  }
  if (from.row_step() != 0) {
    set_row_step(from.row_step());
  }
  if (from.data().size() > 0) {

    data_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.data_);
  }
  if (from.is_dense() != 0) {
    set_is_dense(from.is_dense());
  }
}

void PointCloud2::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ag.ros.PointCloud2)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PointCloud2::CopyFrom(const PointCloud2& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ag.ros.PointCloud2)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PointCloud2::IsInitialized() const {

  return true;
}

void PointCloud2::Swap(PointCloud2* other) {
  if (other == this) return;
  InternalSwap(other);
}
void PointCloud2::InternalSwap(PointCloud2* other) {
  std::swap(header_, other->header_);
  std::swap(height_, other->height_);
  std::swap(width_, other->width_);
  fields_.UnsafeArenaSwap(&other->fields_);
  std::swap(is_bigendian_, other->is_bigendian_);
  std::swap(point_step_, other->point_step_);
  std::swap(row_step_, other->row_step_);
  data_.Swap(&other->data_);
  std::swap(is_dense_, other->is_dense_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata PointCloud2::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = PointCloud2_descriptor_;
  metadata.reflection = PointCloud2_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// PointCloud2

// optional .ag.ros.Header header = 1;
bool PointCloud2::has_header() const {
  return !_is_default_instance_ && header_ != NULL;
}
void PointCloud2::clear_header() {
  if (GetArenaNoVirtual() == NULL && header_ != NULL) delete header_;
  header_ = NULL;
}
const ::ag::ros::Header& PointCloud2::header() const {
  // @@protoc_insertion_point(field_get:ag.ros.PointCloud2.header)
  return header_ != NULL ? *header_ : *default_instance_->header_;
}
::ag::ros::Header* PointCloud2::mutable_header() {
  
  if (header_ == NULL) {
    header_ = new ::ag::ros::Header;
  }
  // @@protoc_insertion_point(field_mutable:ag.ros.PointCloud2.header)
  return header_;
}
::ag::ros::Header* PointCloud2::release_header() {
  // @@protoc_insertion_point(field_release:ag.ros.PointCloud2.header)
  
  ::ag::ros::Header* temp = header_;
  header_ = NULL;
  return temp;
}
void PointCloud2::set_allocated_header(::ag::ros::Header* header) {
  delete header_;
  header_ = header;
  if (header) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:ag.ros.PointCloud2.header)
}

// optional uint32 height = 2;
void PointCloud2::clear_height() {
  height_ = 0u;
}
 ::google::protobuf::uint32 PointCloud2::height() const {
  // @@protoc_insertion_point(field_get:ag.ros.PointCloud2.height)
  return height_;
}
 void PointCloud2::set_height(::google::protobuf::uint32 value) {
  
  height_ = value;
  // @@protoc_insertion_point(field_set:ag.ros.PointCloud2.height)
}

// optional uint32 width = 3;
void PointCloud2::clear_width() {
  width_ = 0u;
}
 ::google::protobuf::uint32 PointCloud2::width() const {
  // @@protoc_insertion_point(field_get:ag.ros.PointCloud2.width)
  return width_;
}
 void PointCloud2::set_width(::google::protobuf::uint32 value) {
  
  width_ = value;
  // @@protoc_insertion_point(field_set:ag.ros.PointCloud2.width)
}

// repeated .ag.ros.PointField fields = 4;
int PointCloud2::fields_size() const {
  return fields_.size();
}
void PointCloud2::clear_fields() {
  fields_.Clear();
}
const ::ag::ros::PointField& PointCloud2::fields(int index) const {
  // @@protoc_insertion_point(field_get:ag.ros.PointCloud2.fields)
  return fields_.Get(index);
}
::ag::ros::PointField* PointCloud2::mutable_fields(int index) {
  // @@protoc_insertion_point(field_mutable:ag.ros.PointCloud2.fields)
  return fields_.Mutable(index);
}
::ag::ros::PointField* PointCloud2::add_fields() {
  // @@protoc_insertion_point(field_add:ag.ros.PointCloud2.fields)
  return fields_.Add();
}
::google::protobuf::RepeatedPtrField< ::ag::ros::PointField >*
PointCloud2::mutable_fields() {
  // @@protoc_insertion_point(field_mutable_list:ag.ros.PointCloud2.fields)
  return &fields_;
}
const ::google::protobuf::RepeatedPtrField< ::ag::ros::PointField >&
PointCloud2::fields() const {
  // @@protoc_insertion_point(field_list:ag.ros.PointCloud2.fields)
  return fields_;
}

// optional bool is_bigendian = 5;
void PointCloud2::clear_is_bigendian() {
  is_bigendian_ = false;
}
 bool PointCloud2::is_bigendian() const {
  // @@protoc_insertion_point(field_get:ag.ros.PointCloud2.is_bigendian)
  return is_bigendian_;
}
 void PointCloud2::set_is_bigendian(bool value) {
  
  is_bigendian_ = value;
  // @@protoc_insertion_point(field_set:ag.ros.PointCloud2.is_bigendian)
}

// optional uint32 point_step = 6;
void PointCloud2::clear_point_step() {
  point_step_ = 0u;
}
 ::google::protobuf::uint32 PointCloud2::point_step() const {
  // @@protoc_insertion_point(field_get:ag.ros.PointCloud2.point_step)
  return point_step_;
}
 void PointCloud2::set_point_step(::google::protobuf::uint32 value) {
  
  point_step_ = value;
  // @@protoc_insertion_point(field_set:ag.ros.PointCloud2.point_step)
}

// optional uint32 row_step = 7;
void PointCloud2::clear_row_step() {
  row_step_ = 0u;
}
 ::google::protobuf::uint32 PointCloud2::row_step() const {
  // @@protoc_insertion_point(field_get:ag.ros.PointCloud2.row_step)
  return row_step_;
}
 void PointCloud2::set_row_step(::google::protobuf::uint32 value) {
  
  row_step_ = value;
  // @@protoc_insertion_point(field_set:ag.ros.PointCloud2.row_step)
}

// optional bytes data = 8;
void PointCloud2::clear_data() {
  data_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& PointCloud2::data() const {
  // @@protoc_insertion_point(field_get:ag.ros.PointCloud2.data)
  return data_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void PointCloud2::set_data(const ::std::string& value) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ag.ros.PointCloud2.data)
}
 void PointCloud2::set_data(const char* value) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ag.ros.PointCloud2.data)
}
 void PointCloud2::set_data(const void* value, size_t size) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ag.ros.PointCloud2.data)
}
 ::std::string* PointCloud2::mutable_data() {
  
  // @@protoc_insertion_point(field_mutable:ag.ros.PointCloud2.data)
  return data_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* PointCloud2::release_data() {
  // @@protoc_insertion_point(field_release:ag.ros.PointCloud2.data)
  
  return data_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void PointCloud2::set_allocated_data(::std::string* data) {
  if (data != NULL) {
    
  } else {
    
  }
  data_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), data);
  // @@protoc_insertion_point(field_set_allocated:ag.ros.PointCloud2.data)
}

// optional bool is_dense = 9;
void PointCloud2::clear_is_dense() {
  is_dense_ = false;
}
 bool PointCloud2::is_dense() const {
  // @@protoc_insertion_point(field_get:ag.ros.PointCloud2.is_dense)
  return is_dense_;
}
 void PointCloud2::set_is_dense(bool value) {
  
  is_dense_ = value;
  // @@protoc_insertion_point(field_set:ag.ros.PointCloud2.is_dense)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace ros
}  // namespace ag

// @@protoc_insertion_point(global_scope)
