#ifndef _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_LIB_ECS_COMPONENT_H_
#define _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_LIB_ECS_COMPONENT_H_

/**
 * Компонент представляет из себя набор данных, поэтому
 * интерфейсу не нужны какие-либо методы.
 *
 * Основные правила написания компонентов следующие:
 * - компоненты содержат только данные, некоторые компоненты могут иметь внутреннее состояние
 * - если есть состояние, есть геттеры-сеттеры
 * - все методы обработки данных должны быть только в системах
 * - поля компонентов объявлены публичными, чтобы системы могли иметь доступ к данным компонента
 */
class IComponent {
 public:
  virtual ~IComponent() = default;
};

#endif  // _HOME_TRIXTER_CLIONPROJECTS_GAMEPROJECTESC_INCLUDE_LIB_ECS_COMPONENT_H_
