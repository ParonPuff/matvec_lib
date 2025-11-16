namespace gfx{
  template<typename T>
  const float* value_ptr(const T& v){
    return reinterpret_cast<const float*>(&v);
  }
}
